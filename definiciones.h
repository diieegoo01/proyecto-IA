// Variable vector de vectores global
vector< vector<string> > arrDepSequencesData, arrivalsData, compCatDepData, compCatResData, departuresData, facilitiesData, gatesData,
imposedConsumptionsData, initialTrainsData, jointArrDepData, parametersData, platformsData, prefPlatData, reusesData, singleTracksData,
trackGroupsData, trainCategoriesData, yardsData;





typedef struct rute{
    string train;
    string time;
    string event_type;
    string resource;
    string gate;
    string Complement;
}rute;

// Vector de rutas de trenes
vector< vector<rute> > rutas;

typedef struct departures_matching{
    string departures;
    string train;
    bool arr;
    string arrivals;
    float cost;
}departures_matching;


typedef struct time{
    int hh;
    int mm;
    int ss;
    double totalmin;
}ttime;


typedef struct date{
    int day;
    int hh;
    int mm;
    int ss;
    double totalmin;
}date;

typedef struct dominio{
        string dep;
        string arr;
        string train;
        string plat_A;
        string plat_D;
        int cost;
        vector<string> dom;
        vector<int> dominio_aux;
}dominio;

vector <dominio > Dominios;


