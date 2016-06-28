
//Funcion que crea un nuevo arreglo de vectores, pero con los dominios de cada Departure, con el fin de trabajar facilmente en el FC.
void llenar_dominio(vector<departures_matching> &matches){
	int i,j;
	string dep;
	dominio dom;
	
	for (int i = 1; i < departuresData.size(); ++i) 
	{	if (matches[i].departures!=""){
			
			dom = dominio(); // Seteamos el dominio.
			dep="Dep"+ std::to_string(i); //concatenación de Dep+i para buscar cada tipo de dep
			dom.dep=dep;
			
			for (int j = 0; j < matches.size(); ++j){ // For que revisa en todo el vector los dominios del departure instanciado
				if (dep==matches[j].departures){
					dom.arr=matches[j].arrivals;
					dom.cost=matches[j].cost;
					dom.dom.push_back(matches[j].train);
					dom.dominio_aux.push_back(0);

				}
			}
			Dominios.push_back(dom); // Agrego los dominios de cada departure a un vector.
		}
	}

}


//Funcion que restablece los dominios de las variables cuando el algoritmo comienza a hacer Backtrack// 
void restablecer_dom(int i){
	for (int j = i+1; j < Dominios.size(); ++j){
		for (int k = 0; k < Dominios[j].dom.size(); ++k){
			if (Dominios[j].dominio_aux[k]==i){
				Dominios[j].dominio_aux[k]=0;
			}
			
		}
		
	}
}

int revisa_restricciones(string instancia,string dom){
	if (instancia==dom) //restricción que revisa si los trenes son iguales.
	{
		return false;
	}else{
		return true;
	}
}


//Funcion encargada de chequear que las restricciones se cumplan//
//Se verifica la variable actual con las posibles futuras variables// 
int Forward_Checking(int i,string instancia){
	int flag;
	cout<<"Entro Forward_Checking i= "<<i<<endl;
	for (int j = i+1; j < Dominios.size(); ++j){
		flag=true;
		for (int k = 0; k < Dominios[j].dominio_aux.size(); ++k){
			if (Dominios[j].dominio_aux[k]==0){
				//Se revisan las restricciones//
				//Si se encuentra algun problema, se retorna False y al valor k del //
				//dominio de la variable j-esima se le asigna i (que es la variable con la cual tiene problemas)//
				//En caso contrario, retorna True y se procede a revisar la siguiente variable j-esima, hasta finalizar// 
				if (revisa_restricciones(instancia,Dominios[j].dom[k])){
					flag=false;
				}
				else{
					cout<<"########## SE ELIMINO "<< Dominios[j].dom[k]<<"DE Dominio variable Dep"<<j+1<<endl;
					Dominios[j].dominio_aux[k]=i+1;

				}
			}
		}
		if(flag){
			return false; //Restorna un False si el dominio se queda vacio.
		}

	}
	return true; // Retornamos un true para seguir adelante.
}

//Funcion principal del forward checking para el Matching, es la encargada de realizar la recursion, ademas de avanzar//
//e ir instanciando las variables hasta llegar a la ultima.//
//Es la encargada de llamar a Forward_Checking() para ir filtrando los dominios//
//Una vez terminada la iteracion, es la encargada de llamar a restablecer_dom()//
void fc(int i){
	string instancia;
	for (int l = 0; l < Dominios[i].dom.size(); ++l){
		instancia=Dominios[i].dom[l];
		cout<<"##############   Instancia "<<i+1<<"="<<instancia<<"   ###############"<<endl;

		if (Dominios[i].dominio_aux[l]==0){
			if (i==Dominios.size()-1){
				cout<<"SOLUCION ENCONTRADA"<<endl;
				    for (int i = 0; i < Dominios.size(); ++i){
				        cout<<Dominios[i].arr<<endl;
				        for (int j = 0; j < Dominios[i].dom.size(); ++j)
				        {	if (Dominios[i].dominio_aux[j]==0){
				        	Dominios[i].train=Dominios[i].dom[j]; //Guardamos el mejor tren asignado al matching departure.
				        	cout<<Dominios[i].train<<endl;
				        	cout<<Dominios[i].dep<<"   Costo=";
				        	cout<<Dominios[i].cost<<endl;

				        	}
				        }
				        cout<<"\n"<<endl;
				    }
				    cin.get();

			}else{
				if (Forward_Checking(i,instancia)){ // Si no tenemos problemas de dominios vacios, avanzamos a la siguiente iteración
					fc(i+1);
				}
				restablecer_dom(i); // Se restablecen las variables 
			}
		}
	}
}


//Funcion que crea un nuevo arreglo de vectores, pero con los dominios de cada Departure, con el fin de trabajar facilmente en el FC.
void llenar_dominio(vector<departures_matching> &matches){
	int i,j;
	string dep;
	dominio dom;
	
	for (int i = 1; i < departuresData.size(); ++i) 
	{	if (matches[i].departures!=""){
			
			dom = dominio(); // Seteamos el dominio.
			dep="Dep"+ std::to_string(i); //concatenación de Dep+i para buscar cada tipo de dep
			dom.dep=dep;
			
			for (int j = 0; j < matches.size(); ++j){ // For que revisa en todo el vector los dominios del departure instanciado
				if (dep==matches[j].departures){
					dom.arr=matches[j].arrivals;
					dom.cost=matches[j].cost;
					dom.dom.push_back(matches[j].train);
					dom.dominio_aux.push_back(0);

				}
			}
			Dominios.push_back(dom); // Agrego los dominios de cada departure a un vector.
		}
	}

}


void FC_plataformas(int i){
	string instancia;
	for (int l = 1; l < platformsData.size(); ++l){
		instancia=platformsData[l][0];
		cout<<"##############   Instancia "<<l<<"="<<instancia<<"   ###############"<<endl;

	}

}





/*
vector<departures_matching> fc(vector<departures_matching> &matches,int k){
	int flag;
	vector <departures_matching> matches_aux;
	vector <dominio> dom;
	matches_aux=matches;
	string instancia,dep;
	llenar_dominio(matches);
	
	

	//cin.get();
	for (int i=k ; i < matches.size(); ++i)
	{
		if (matches_aux[i].train==""){fc(matches_aux,i+1);}
		dep=matches_aux[i].departures;
		instancia=matches_aux[i].train;
		cout<<"departure"<<"="<<dep<<"="<<instancia<<endl;
		flag=revisa_dominio(dep,matches_aux);
		if (flag!=0){
			for (int j = i; j < matches_aux.size(); ++j){ // For que revisa todos los dominios de las demas instancias
				if (dep!=matches_aux[j].departures && instancia==matches_aux[j].train){
					matches_aux[j].train="";

					
				}
			}
			fc(matches_aux,i+1);
		}else{
		cout<< "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"<<endl;
		//Se chequean las restricciones//
				//si no encuentra ni un problema se procede a llamar a fc(i+1)//
		
		if (flag!=0)
		{
			fc(matches,k);
		}
		
		
		}
				
	}

	return matches_aux;



} 
*/




