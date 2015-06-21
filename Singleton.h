#ifndef SINGLETON_H
#define SINGLETON_H

template <typename TYPE>
class Singleton
{
public:
    static TYPE *Create() {
        if (!m_instance)
            m_instance = new TYPE;

        return m_instance;
    }

    static void Destroy() {
        if (m_instance) {
            delete m_instance;
            m_instance = nullptr;
        }
    }

protected:
    Singleton() { }
    ~Singleton() { }

private:
    static TYPE *m_instance;
};

template <typename TYPE>
TYPE *Singleton<TYPE>::m_instance = nullptr;

#endif // SINGLETON_H
