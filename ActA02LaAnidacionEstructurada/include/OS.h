//Header para manejar terminal
//Guardia para evitar dobles integraciones en compilado
#ifndef OS_H
#define OS_H
#ifdef _WIN32
//Clase OS para limpiar pantalla,color y banners.
class OS{
    //Variables privadas
    private:
        //Constantes y caracteres especiales
        const char OMINACENTUADA = 162;
        const char AMINACENTUADA = 160;
        const char COPYRIGHT = 184;
        const char REGISTEREDTRADEMARK = 169;
        const char ESQSIZQ = 201;
        const char ESQSDER = 187;
        const char ESQIIZQ = 200;
        const char ESQIDER = 188;
        const char VERTICAL = 186;
        const char HORIZONTAL = 205;
        const char ENYEMIN= 164;
        const bool WINDOWS= true;
        const bool LINUX= false;
        const char CUADRADO= 253;
        const char PROMPT= 175;
        const char ARROBA= 64;
    //Métodos de clase OS
    public:
        //Constructor
        OS(void);
        //Constructor Copia
        //OS(const OS &OSOriginal);
        //Destructor
        ~OS();
        //Función banner principal
        void banner(void);
        //Función para cambio de color terminal
        void ColorCMD(char * Color);
        //Función para manejo de pausas al finalizar funciones
        void Pausa(void);
        //Función para poder Borrar caracteres de terminal - stdout
        void BorrarConsola(void);
        //Función para dar un delay a la terminal
        void Dormir(int dormir);
};
#elif __linux__
//Clase OS para limpiar pantalla,color y banners.
class OS{
    //Variables privadas
    private:
        //Constantes y caracteres especiales
        const char OMINACENTUADA = '\u00F3';
        const char AMINACENTUADA = '\u00E1';
        const char COPYRIGHT = '\u00A9';
        const char REGISTEREDTRADEMARK = '\u00AE';
        const char ESQSIZQ = '\u2554';
        const char ESQSDER = '\u2557';
        const char ESQIIZQ = '\u255A';
        const char ESQIDER = '\u255D';
        const char VERTICAL = '\u2551';
        const char HORIZONTAL = '\u2550';
        const char ENYEMIN= '\u00F1';
        const bool WINDOWS= false;
        const bool LINUX= true;
        const char PROMPT= '\u0BB';
        const char ARROBA= '\u040';
    //Métodos de clase OS
    public:
        //Constructor
        OS(void);
        //Constructor Copia
        //OS(const OS &OSOriginal);
        //Destructor
        ~OS();
        //Función banner principal
        void banner(void);
        //Función para cambio de color terminal
        void ColorCMD(void);
        //Función para manejo de pausas al finalizar funciones
        void Pausa(void);
        //Función para poder Borrar caracteres de terminal - stdout
        void BorrarConsola(void);
        //Función para dar un delay a la terminal
        void Dormir(int dormir);
};
#endif
#endif