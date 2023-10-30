#include "BLESecurity.h"
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"

class MySecurityCallbacks : public BLESecurityCallbacks {
public:
    virtual uint32_t onPassKeyRequest() {
        // This method is called when the peer device requests a passkey.
        // You should generate a 6-digit passkey and return it here.
        return 123456;  // Replace with your desired passkey.
    }

    virtual void onPassKeyNotify(uint32_t pass_key) {
        // This method is called when the peer device notifies the passkey.
        // You can choose to display the passkey to the user if needed.
        // For simplicity, you can just log it.
        Serial.print("Received passkey: ");
        Serial.println(pass_key);
    }

    virtual bool onSecurityRequest() {
        // This method is called when the peer device requests security authorization.
        // You can choose to accept or reject the request here.
        // For simplicity, always accept it.
        return true;
    }

    virtual void onAuthenticationComplete(esp_ble_auth_cmpl_t auth_cmpl) {
        // This method is called when the authentication process is completed.
        // You can perform additional actions after successful authentication if needed.
        Serial.println("Authentication completed");
    }

    virtual bool onConfirmPIN(uint32_t pin) {
        // This method is called when a PIN confirmation is required.
        // You can choose to confirm or reject the PIN.
        // For simplicity, always confirm it.
        return true;
    }
};

void setup() {
    Serial.begin(115200);
    Serial.println("Starting BLE work!");

    // Initialize Bluetooth and set the security callback
    BLEDevice::init("connectme");
    BLEServer *pServer = BLEDevice::createServer();
    BLEService *pService = pServer->createService(SERVICE_UUID);
    BLECharacteristic *pCharacteristic = pService->createCharacteristic(
        CHARACTERISTIC_UUID,
        BLECharacteristic::PROPERTY_READ |
        BLECharacteristic::PROPERTY_WRITE
    );

    pCharacteristic->setValue("Hello World says Neil");
    pService->start();

    // Set the security parameters and callbacks
    BLESecurity bleSecurity;
    bleSecurity.setAuthenticationMode(ESP_LE_AUTH_BOND);
    bleSecurity.setCapability(ESP_IO_CAP_OUT);
    bleSecurity.setKeySize(16);
    bleSecurity.setInitEncryptionKey(ESP_BLE_ENC_KEY_MASK | ESP_BLE_ID_KEY_MASK);
    bleSecurity.setRespEncryptionKey(ESP_BLE_ENC_KEY_MASK | ESP_BLE_ID_KEY_MASK);
    //bleSecurity.setAuthenticationMode(new esp_ble_auth_req_t);  

    // BLEAdvertising *pAdvertising = pServer->getAdvertising();  // this still is working for backward compatibility
    BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
    pAdvertising->addServiceUUID(SERVICE_UUID);
    pAdvertising->setScanResponse(true);
    pAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
    pAdvertising->setMinPreferred(0x12);
    BLEDevice::startAdvertising();

    Serial.println("Characteristic defined! Now you can read it on your phone!");
}

void loop() {
    // put your main code here, to run repeatedly:
    delay(2000);
}
