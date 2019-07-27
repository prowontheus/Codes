#ifndef _SIMPLE_DLLEXPORT_H
#define _SIMPLE_DLLEXPORT_H

#ifdef SIMPLEDLL_EXPORT
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

class DLL_EXPORT SimpleDLLClass
{

    public:
        SimpleDLLClass();
        virtual ~SimpleDLLClass();
        virtual int getValue() {return m_nValue;};
    private:
        static int m_nValue;
};
#endif
