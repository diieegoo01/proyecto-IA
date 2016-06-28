//
//  main.cpp
//  Proyecto IA
//
//  Created by Diego Reyes Delgado on 6/18/16.
//  Copyright © 2016 Diego Reyes Delgado. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <chrono>

using namespace std;

// Carga de de definiciones y funciones

#include "definiciones.h"
#include "load_data.h"
#include "restricciones.h"
#include "matching.h"
#include "FC.h"



int main(int argc, char **argv) {
    
    clock_t tStart = clock(); // tiempo usado del procesador
    string instance = argv[1]; // Lee nombre de la instancia por linea de comando
    
    carga_datos(instance); // carga de datos.
    vector <departures_matching> match,nuevo_matching;
    float cost = 0;

    MatchingDepartures(match); // acotando las instancias posibles de matching departures
    llenar_dominio(match);

    cout<<"################################ DOMINIOS #####################################"<<endl;

    for (int i = 0; i < Dominios.size(); ++i)
    {
        cout<<Dominios[i].dep<<endl;
        for (int j = 0; j < Dominios[i].dom.size(); ++j)
        {
            cout<<Dominios[i].dom[j]<<"="<<Dominios[i].dominio_aux[j]<<"  --  ";
        }
        cout<<"\n"<<endl;
    }
    cout<<"################################################################################"<<endl;

    
    fc(0);
    FC_plataformas(0);


    cout<<"Dominio depX"<<endl;
    for(size_t l=0;l<match.size();l++){
        cost = cost + match[l].cost;
        cout<<"Departure: "<<match[l].departures<<" Tiene posible el tren: "<<match[l].train<<" || del Arrivals: "
        <<match[l].arrivals<< " con un costo de: "<< match[l].cost<< endl;
    }
    cout<<"Costo total "<<cost<<endl;
    cout<< "la ejecucion fue de: "<<(double)(clock() - tStart)/CLOCKS_PER_SEC<<" segundos"<<endl;
    return 0;

    
    
    
    
    
}