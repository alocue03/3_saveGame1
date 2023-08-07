
#include <iostream>
#include <fstream>

#define MAXNAMESIZE 16

enum EWeapon
{
    none, sword, lance, bow, olympia
};

struct SGameData
{
    char name[MAXNAMESIZE];
    EWeapon  currentWeapon;
    int enemysKilled;
    unsigned int seleccion;
};

void log(const char* msg)
{
    std::cout << msg << "\n";
}


int main()
{
    //leer el archivo de savegame
    std::fstream savefile("data.sav", std::ios::in | std::ios::out);

    if (savefile.is_open())
    {
        log("Savefile abierto");

        //leer datos del archivo
        SGameData data;
        savefile.read(data.name, MAXNAMESIZE);
        savefile.read((char*)&data.currentWeapon, 4);
        savefile.read((char*)&data.enemysKilled, 4);
        savefile.read((char*)&data.seleccion, 4);

        std::cout << "Hola " << data.name << ". yo sere tu guia en esta aventura.";
        int seleccion = 0;
        log("Presiona 1 para iniciar un nuevo juego. Presiona 2 para continuar\n");
        std::cin >> seleccion;
        if (seleccion == 1)
        {
            log("Inicializando Juego\n");
            std::cout << " Como estas empezando tu arma actual es: " << data.currentWeapon << ". que son tus punos " "\n" "y has matado a " << data.enemysKilled;
            int seleccion = 0;
            log("Estas llegando a tu nuevo lugar de casa, Dresrossa. Yo sere tu guia: Pica");
            log("1. Que feo está");
            log("2. Bueno, he estado en peores");
            log("3. Ay pero que bonito");
            std::cin >> seleccion;
            if (seleccion == 1)
            {
                log("Pica: si esta feo la neta, pero eres un cazador de rango E tampoco te da para mucho wey jajajaja");
                log("Pica: Como soy un dios generoso te voy a dar 100 monedas para que te compres el arma que quieras, elige una");
                log("1. Espada");
                log("2. Lanza");
                log("3. Arco");
                log("4. Olympia");
                std::cin >> seleccion;
                if (seleccion == 1)
                {
                    std::cout << data.name << ": Me llevare la espada, nunca puedes ir mal con una espada \n";
                    log("Pica: nmms pinche basica");
                    data.currentWeapon = sword;
                    std::cout << "Ahora tienes equipada la" << data.currentWeapon << "\n";
                    if (savefile.is_open())
                    {
                        savefile.seekp(0, std::ios::beg);
                        savefile.write((const char*)&data, sizeof(SGameData));
                        log("Pica: Guardando crack");
                    }
                }
                if (seleccion == 2)
                {
                    std::cout << data.name << ": me llevare la lanza, se ve chida \n";
                    data.currentWeapon = lance;
                    log("Pica: solia arma de combate a media distancia");
                    std::cout << "Ahora tienes equipada la " << data.currentWeapon << "\n";
                    if (savefile.is_open())
                    {
                        savefile.seekp(0, std::ios::beg);
                        savefile.write((const char*)&data, sizeof(SGameData));
                        log("Pica: Guardando crack");
                    }
                }
                if (seleccion == 3)
                {
                    std::cout << data.name << ": Tomare el arco";
                    data.currentWeapon = bow;
                    log("Pica: Veo que eres un cazador de distancia, pero por que tu personaje no es un elfo? no la seleccionaste al principio cuando te dieron a elegir la raza?");
                    std::cout << data.name << ": Nunca me dieron a elegir la raza \n";
                    log("Pica: ...........");
                    log("Pica: Se me olvido que mi creador no le metio eso al juego, perdon bro");
                    std::cout << "Ahora tienes equipada la " << data.currentWeapon << "\n";
                    if (savefile.is_open())
                    {
                        savefile.seekp(0, std::ios::beg);
                        savefile.write((const char*)&data, sizeof(SGameData));
                        log("Pica: Guardando crack");
                    }
                }
                if (seleccion == 4)
                {
                    std::cout << data.name << ": Tomare la olympia";
                    data.currentWeapon = olympia;
                    log("Pica: Si pues si, se veia que te ibas a ir por la facil, Diamante me debe 20 dolares jajaja");
                    std::cout << data.name << ": Como que la facil? \n";
                    log("Pica: nmms, en este nivel hay puro slime y tu llevas una escopeta mamon");
                    std::cout << "Ahora tienes equipada la " << data.currentWeapon << "\n";
                    if (savefile.is_open())
                    {
                        savefile.seekp(0, std::ios::beg);
                        savefile.write((const char*)&data, sizeof(SGameData));
                        log("Pica: Guardando crack");
                    }
                }

            }
            else if (seleccion == 2)
            {
                log("Pica: No me sorprende, me dijero que eras un cazador de Clase E, que noob, se ve que apenas empiezas el juego");
                log("Pica: Como soy un dios generoso te voy a dar 100 monedas para que te compres el arma que quieras, elige una");
                log("1. Espada");
                log("2. Lanza");
                log("3. Arco");
                log("4. Olympia");
                std::cin >> seleccion;
                if (seleccion == 1)
                {
                    std::cout << data.name << ": Me llevare la espada, nunca puedes ir mal con una espada \n";
                    log("Pica: nmms pinche basica");
                    data.currentWeapon = sword;
                    std::cout << "Ahora tienes equipada la" << data.currentWeapon << "\n";
                    if (savefile.is_open())
                    {
                        savefile.seekp(0, std::ios::beg);
                        savefile.write((const char*)&data, sizeof(SGameData));
                        log("Pica: Guardando crack");
                    }
                }
                if (seleccion == 2)
                {
                    std::cout << data.name << ": me llevare la lanza, se ve chida \n";
                    data.currentWeapon = lance;
                    log("Pica: solia arma de combate a media distancia");
                    std::cout << "Ahora tienes equipada la " << data.currentWeapon << "\n";
                    if (savefile.is_open())
                    {
                        savefile.seekp(0, std::ios::beg);
                        savefile.write((const char*)&data, sizeof(SGameData));
                        log("Pica: Guardando crack");
                    }
                }
                if (seleccion == 3)
                {
                    std::cout << data.name << ": Tomare el arco";
                    data.currentWeapon = bow;
                    log("Pica: Veo que eres un cazador de distancia, pero por que tu personaje no es un elfo? no la seleccionaste al principio cuando te dieron a elegir la raza?");
                    std::cout << data.name << ": Nunca me dieron a elegir la raza \n";
                    log("Pica: ...........");
                    log("Pica: Se me olvido que mi creador no le metio eso al juego, perdon bro");
                    std::cout << "Ahora tienes equipada la " << data.currentWeapon << "\n";
                    if (savefile.is_open())
                    {
                        savefile.seekp(0, std::ios::beg);
                        savefile.write((const char*)&data, sizeof(SGameData));
                        log("Pica: Guardando crack");
                    }
                }
                if (seleccion == 4)
                {
                    std::cout << data.name << ": Tomare la olympia";
                    data.currentWeapon = olympia;
                    log("Pica: Si pues si, se veia que te ibas a ir por la facil, Diamante me debe 20 dolares jajaja");
                    std::cout << data.name << ": Como que la facil? \n";
                    log("Pica: nmms, en este nivel hay puro slime y tu llevas una escopeta mamon");
                    std::cout << "Ahora tienes equipada la " << data.currentWeapon << "\n";
                    if (savefile.is_open())
                    {
                        savefile.seekp(0, std::ios::beg);
                        savefile.write((const char*)&data, sizeof(SGameData));
                        log("Pica: Guardando crack");
                    }
                }
            }
            else if (seleccion == 4)
            {
                log("Pica: Se que es mi casa y todo pero esta culero no te hagas, osea gracias pero esta culero, no tienes por que ser buena onda");
                log("Pica: Como soy un dios generoso te voy a dar 100 monedas para que te compres el arma que quieras, elige una");
                log("1. Espada");
                log("2. Lanza");
                log("3. Arco");
                log("4. Olympia");
                std::cin >> seleccion;
                if (seleccion == 1)
                {
                    std::cout << data.name << ": Me llevare la espada, nunca puedes ir mal con una espada \n";
                    log("Pica: nmms pinche basica");
                    data.currentWeapon = sword;
                    std::cout << "Ahora tienes equipada la" << data.currentWeapon << "\n";
                    if (savefile.is_open())
                    {
                        savefile.seekp(0, std::ios::beg);
                        savefile.write((const char*)&data, sizeof(SGameData));
                        log("Pica: Guardando crack");
                    }
                }
                if (seleccion == 2)
                {
                    std::cout << data.name << ": me llevare la lanza, se ve chida \n";
                    data.currentWeapon = lance;
                    log("Pica: solia arma de combate a media distancia");
                    std::cout << "Ahora tienes equipada la " << data.currentWeapon << "\n";
                    if (savefile.is_open())
                    {
                        savefile.seekp(0, std::ios::beg);
                        savefile.write((const char*)&data, sizeof(SGameData));
                        log("Pica: Guardando crack");
                    }
                }
                if (seleccion == 3)
                {
                    std::cout << data.name << ": Tomare el arco";
                    data.currentWeapon = bow;
                    log("Pica: Veo que eres un cazador de distancia, pero por que tu personaje no es un elfo? no la seleccionaste al principio cuando te dieron a elegir la raza?");
                    std::cout << data.name << ": Nunca me dieron a elegir la raza \n";
                    log("Pica: ...........");
                    log("Pica: Se me olvido que mi creador no le metio eso al juego, perdon bro");
                    std::cout << "Ahora tienes equipada la " << data.currentWeapon << "\n";
                    if (savefile.is_open())
                    {
                        savefile.seekp(0, std::ios::beg);
                        savefile.write((const char*)&data, sizeof(SGameData));
                        log("Pica: Guardando crack");
                    }
                }
                if (seleccion == 4)
                {
                    std::cout << data.name << ": Tomare la olympia";
                    data.currentWeapon = olympia;
                    log("Pica: Si pues si, se veia que te ibas a ir por la facil, Diamante me debe 20 dolares jajaja");
                    std::cout << data.name << ": Como que la facil? \n";
                    log("Pica: nmms, en este nivel hay puro slime y tu llevas una escopeta mamon");
                    std::cout << "Ahora tienes equipada la " << data.currentWeapon << "\n";
                    if (savefile.is_open())
                    {
                        savefile.seekp(0, std::ios::beg);
                        savefile.write((const char*)&data, sizeof(SGameData));
                        log("Pica: Guardando crack");
                    }
                }
            }
        }
    }
    else
    {
        log("Crear savefile vacio e inicial");
        SGameData data;
        std::cin >> data.name;
        log("Escribe tu nombre aventurero");
        data.currentWeapon = EWeapon::none;
        data.enemysKilled = 0;




        savefile.open("data.sav", std::ios::out);
        if (savefile.is_open())
        {
            //dumpear la estructura data
            savefile.seekp(0, std::ios::beg);
            savefile.write((const char*)&data, sizeof(SGameData));
        }
        else
        {
            log("No se pudo crear el archivo :(");
        }
    }
    savefile.close();

    return 0;

}
