//funcion que lee los datos de las instancias y los guarda en vector de vectores
//recibe el nombre del archivo y las columnas de los archivos
vector< vector<string> > loadData(const char* filename, int value) {
    ifstream file(filename);
    vector< vector<string> > data;
    vector<string> row(value);
    string column, tmp;
    int cont = 0;
    if(file.is_open()) {
        while (getline(file, column, ';')) {
            if(cont == 0) { column.erase(0, 1); }
            row.push_back(column);
            cont++;
            if(cont == value) {
                data.push_back(row);
                row.clear();
                cont = 0;
            }
        }
        file.close();
    }
    
    return data;
}

void carga_datos(string instance){
    
    arrDepSequencesData = loadData(("instancias/"+ instance + "/arrDepSequences.csv").c_str(), 3);
    arrivalsData = loadData(("instancias/"+ instance + "/arrivals.csv").c_str(), 11);
    compCatDepData = loadData(("instancias/"+ instance + "/compCatDep.csv").c_str(), 2);
    compCatResData = loadData(("instancias/"+ instance + "/compCatRes.csv").c_str(), 2);
    departuresData = loadData(("instancias/"+ instance + "/departures.csv").c_str(), 8);
    facilitiesData = loadData(("instancias/"+ instance + "/facilities.csv").c_str(), 3);
    gatesData = loadData(("instancias/"+ instance + "/gates.csv").c_str(), 6);
    imposedConsumptionsData = loadData(("instancias/"+ instance + "/imposedConsumptions.csv").c_str(), 7);
    initialTrainsData = loadData(("instancias/"+ instance + "/initialTrains.csv").c_str(), 5);
    parametersData = loadData(("instancias/"+ instance + "/parameters.csv").c_str(), 2);
    platformsData = loadData(("instancias/"+ instance + "/platforms.csv").c_str(), 2);
    prefPlatData = loadData(("instancias/"+ instance + "/prefPlat.csv").c_str(), 2);
    reusesData = loadData(("instancias/"+ instance + "/reuses.csv").c_str(), 2);
    singleTracksData = loadData(("instancias/"+ instance + "/singleTracks.csv").c_str(), 3);
    trackGroupsData = loadData(("instancias/"+ instance + "/trackGroups.csv").c_str(), 3);
    trainCategoriesData = loadData(("instancias/"+ instance + "/trainCategories.csv").c_str(), 7);
    yardsData = loadData(("instancias/"+ instance + "/yards.csv").c_str(), 2);
    
}