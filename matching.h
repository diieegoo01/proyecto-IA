
void MatchingDepartures(vector<departures_matching> &matching){
    float costo = 0;
    int flag;
    int diferencia_D,diferencia_A = 0;
    vector< vector<string> > init_trains = initialTrainsData; // Se guardan los datos de los trenes iniciales dados por la instancia.
    departures_matching matching_aux;
    ttime departure_time, arrival_time, res_time;  //variables de tiempo hrs
    date departute_date, arrival_date;            // variables de tiempo días
    res_time = get_time(parametersData[12][1]);
    
    for(int i=1; i < departuresData.size(); i++){  //recorremos todo el los vectores de Departures cargados
        flag = 0;
        departute_date = get_date(departuresData[i][1]); //guardamos en una estrutura tipo "date" la fecha del Departure
        for(int j=1; j< arrivalsData.size();j++){
            arrival_date = get_date(arrivalsData[j][2]); // Obtenemos la fecha del Arrival y lo guardamos en la estructura
            
            if( departute_date.day == arrival_date.day && departute_date.totalmin > arrival_date.totalmin){ // comparamos las fechas y tiempos de un departure y un arrival
                /* Se verifica que el tiempo entre llegada y salida sea mayor o igual
                 al tiempo minimo que se debe estar en el recuerso */
                if(departute_date.totalmin - arrival_date.totalmin >= res_time.totalmin ){
                    departure_time = get_time(departuresData[i][5]); // Obtiene el tiempo MaxDwella
                    arrival_time = get_time(arrivalsData[j][8]); // Obtiene el tiempo MaxDwella
                    
                    // Verificamos Si el tiempo de viaje (DEP-ARR) es menor que el tiempo Maximo de un arrival y de un departure.
                    if((departute_date.totalmin - arrival_date.totalmin <= arrival_time.totalmin) &&
                       (departute_date.totalmin - arrival_date.totalmin <=  departure_time.totalmin)){
                        departure_time = get_time(departuresData[i][4]); // Obtiene los tiempos idealDwell
                        arrival_time= get_time(arrivalsData[j][7]); // Obtiene los tiempos idealDwell


                        // Verificamos si sobrepasa el Dwell ideal de Arrival, calculamos los costos por quedarse un tiempo extra la plataforma.
                        if((departute_date.totalmin - arrival_date.totalmin) > arrival_time.totalmin){
                            diferencia_A = (departute_date.totalmin - arrival_date.totalmin) - arrival_time.totalmin;
                            costo = costo + (diferencia_A*60)*atof(parametersData[10][1].c_str());
                        }
                        // Verificamos si sobrepasa el Dwell ideal de Departure, calculamos los costos por quedarse un tiempo extra la plataforma.
                        if((departute_date.totalmin - arrival_date.totalmin) > departure_time.totalmin){
                            diferencia_D = (departute_date.totalmin - arrival_date.totalmin) - departure_time.totalmin;
                            costo = costo + (diferencia_D*60)*atof(parametersData[10][1].c_str());
                        }

                        for(int k = 1; k<reusesData.size();k++){
                            if(departuresData[i][0].compare(reusesData[k][1])!=0){
                                
                                if(arrivalsData[j][0].compare(reusesData[k][0]) == 0){
                                   
                                    costo = costo + atof(parametersData[11][1].c_str());
                                    
                                }
                            }
                        }
                        matching_aux.arrivals = arrivalsData[j][0];
                        matching_aux.train = arrivalsData[j][1];
                        matching_aux.cost = costo;
                        matching_aux.departures = departuresData[i][0];
                        matching_aux.arr = 1;
                        matching.push_back(matching_aux);
                        
                        flag = 1;
                        costo=0;
                        
                        
                    }
                }
            }
        }
        if(flag == 0){ // Si no hay asignaciones, se le asigna tren inicial
            if((init_trains.size() - 1) > 0){
                matching_aux.train = init_trains[1][0];
                matching_aux.departures = departuresData[i][0];
                matching_aux.arr = 0;
                matching_aux.arrivals = "Tren inicial";
                matching_aux.cost = 0;
                matching.push_back(matching_aux);
                init_trains.erase(init_trains.begin() + 1);
            }
            else{ // Si no hay, no quedan cubierto
                matching_aux.departures = "Sin cubrir";
                matching_aux.arr = 0;
                matching_aux.arrivals = "Sin cubrir";
                matching_aux.train = "Sin cubrir";
                matching_aux.cost = atof(parametersData[16][0].c_str());
                matching.push_back(matching_aux);
            }
        }
    }
}
