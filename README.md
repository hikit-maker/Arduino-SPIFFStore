# Arduino-SPIFFStore
Helper library to store integers into SPIFFS as documents.

NOTE: you have to **enable** SPIFFS under `Tools > Flash Size > **(**K SPIFFS)`


## Example code

After a while you can restart your arduino and the count will reset.

```

#include "FS.h"
#include "Store.hpp"

int myInt = 0;
String myIntKey = "someUniqueKey";

void setup()
{
    Serial.begin(115200);
    delay(100);

    Store.begin(SPIFFS);

    int storedInt = Store.getInt(myIntKey);  // If the key doesn't exist, it returns -1
    if (storedInt != -1)
    {
        myInt = storedInt;
    }
}

void loop()
{
    Store.saveInt(myIntKey, myInt);
    Serial.print("Storing number: ");
    Serial.println(myInt);
    
    delay(1000);

    int storedInt = Store.getInt(myIntKey);
    Serial.print("My stored number is: ");
    Serial.println(storedInt);
    
    delay(1000);

    myInt += 1;
}
```
