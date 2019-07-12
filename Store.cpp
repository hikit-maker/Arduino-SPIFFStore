#include "Store.hpp"

void StoreClass::begin(FS &spiffs)
{
    if (_initialized)
    {
        return;
    }

    this->spiffs = &spiffs;
    this->spiffs->begin();
    this->_initialized = true;
}

bool StoreClass::saveInt(String key, int value)
{
    fs::File document = this->fileWriter(key);
    if ( !document )
    {
        return false;
    }
    
    document.println(value);
    document.close();
    return true;
}

int StoreClass::getInt(String key)
{
    fs:File document = this->fileReader(key);
    if ( !document )
    {
        return -1;
    }

    String rawInt = document.readStringUntil('\n');
    return rawInt.toInt();
}

fs::File StoreClass::fileWriter(String path)
{
    char *mode = "w";
    return this->spiffs->open(path, mode);
}

fs::File StoreClass::fileReader(String path)
{
    if (this->spiffs->exists(path))
    {
        return this->spiffs->open(path, "r");
    }
    
    return File();
}

#if !defined(NO_GLOBAL_INSTANCES) && !defined(NO_GLOBAL_STORE)
    StoreClass Store;
#endif
