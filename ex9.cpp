#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// écrire une fonction nb_char_in_file(filename, c) qui compte le nombre
// de fois que la caractère c apparait dans le fichier. Il doit retourner
// une valeur négative en cas d'impossibilité d'ouvrir le fichier
int nb_char_in_file(string filename, char c){
    ifstream f(filename);
    int compteur = 0;
    string s;
    if(!f){
        cerr <<"-1"<<endl;
        return 0;
    }
    while(f){
        getline(f, s);
        for (char &g : s){
            if(g==c)
                compteur++;
        }
    }
    return compteur;
}

int main() {
   cout << "Entrez le nom du fichier : " << flush;
   string filename; cin >> filename;
   cout << "Entrez le caractère : " << flush;
   char c; cin >> c;

   auto n = nb_char_in_file(filename,c);
   if(n >= 0)
      cout << "Le fichier contient " << n << " fois le caractère " << c << endl;
   else
      cout << "Le fichier est illisible";
}