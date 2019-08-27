#ifndef __STORE_H_

#define __STORE_H_

#include "FS.h"
#include "Arduino.h"

class StoreClass {
    public:
        void begin(fs::FS &spiffs);
        bool save(String key, int value);
        bool save(String key, String value);
        int getInt(String key);
        String getString(String key);

    private:
        fs::File fileReader(String path);
        fs::File fileWriter(String path);
        
        bool _initialized;
        fs::FS *spiffs;
};

#if !defined(NO_GLOBAL_INSTANCES) && !defined(NO_GLOBAL_STORE)
    extern StoreClass Store;
#endif

#endif  // __STORE_H_
