//
//  restricciones.cpp
//  Proyecto IA
//
//  Created by Diego Reyes Delgado on 6/19/16.
//  Copyright © 2016 Diego Reyes Delgado. All rights reserved.
//
date get_date(string v){
    date d;
    string aux;
    aux= v.substr(1,2);
    d.day = atoi(aux.c_str());
    aux = v.substr(3,2);
    d.hh = atoi(aux.c_str());
    aux = v.substr(6,2);
    d.mm = atoi(aux.c_str());
    aux = v.substr(9,2);
    d.ss = atoi(aux.c_str());
    d.totalmin =60*d.hh + d.mm + d.ss/60;
    return d;
}

ttime get_time(string v){
    ttime t;
    string aux;
    aux = v.substr(0,2);
    t.hh = atoi(aux.c_str());
    aux = v.substr(3,2);
    t.mm = atoi(aux.c_str());
    aux = v.substr(5,2);
    t.ss = atoi(aux.c_str());
    t.totalmin =60*t.hh + t.mm + t.ss/60; // Tiempo en minutos
    return t;
}



