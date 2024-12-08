#ifndef CUSTOMMODEL3SINGLETON_H
#define CUSTOMMODEL3SINGLETON_H

#include "custommodel3.h"
#include <QObject>

class CustomModel3Singleton : public QObject {
    Q_OBJECT
public:
    static QObject* instanceProvider(QQmlEngine* engine, QJSEngine* scriptEngine) {
        Q_UNUSED(engine)
        Q_UNUSED(scriptEngine)

        // Ensure a single instance of CustomModel3
        if (!s_instance) {
            s_instance = new CustomModel3();
            s_instance->addEntry(1, "First entry");
            s_instance->addEntry(2, "Second entry");
            s_instance->addEntry(3, "Third entry");
        }
        return s_instance;
    }

private:
    static CustomModel3* s_instance; // Singleton instance
};

#endif // CUSTOMMODEL3SINGLETON_H
