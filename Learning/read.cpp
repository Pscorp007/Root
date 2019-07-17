#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

int main(){
  // string en,g;
  // cout<<"Input Event number"<<endl;
  // cin>>en;
  // cout<<"Enter type of graph you want"<<endl;
  // cin>>g;
  //
  // if(g=="HitGlobal_xy"){
  //   string final = "event"+en+"-hits.csv";
  //   ifstream Input_File(final);
  //   int hit_id,volume_id,layer_id,module_id;
  //   double x,y,z;
  //   char c;
  //   string s;
  //   Input_File>>s;
  //   while(Input_File.good()){
  //     Input_File>>hit_id>>c>>x>>c>>y>>c>>z>>c>>volume_id>>c>>layer_id>>c>>module_id;
  //     cout<<x<<" "<<y<<" "<<z<<endl;
  //   }
  // }
  // else if(g=="HitGlobal_rz"){}
  // else if(g=="NHit_vs_theta"){
  //   ifstream Input_File2("event000001000-particles.csv");
  //   string particle_id;
  //   int q;
  //   double vx,vy,vz,px,py,pz,nhits;
  //   char c2;
  //   string s2;
  //   Input_File2>>s2;
  //   while(Input_File2.good()){
  //     Input_File2>>particle_id>>c2>>vx>>c2>>vy>>c2>>vz>>c2>>px>>c2>>py>>c2>>pz>>c2>>q>>c2>>nhits;
  //     double theta = acos(vz/(sqrt(  (  (int)vx*(int)vx  )  +  (  (int)vy*(int)vy  )  +  (  (int)vz*(int)vz  )  )));
  //     cout<<setprecision(9)<<theta<<"  "<<nhits<<endl;
  //   }
  // }
  // else if(g=="NHitPair_vs_dist"){}
  //
  //

  // ifstream Input_File(s1);
  // int hit_id,volume_id,layer_id,module_id;
  // double x,y,z;
  // char c;
  // string s;
  // Input_File>>s;
  // while(Input_File.good()){
  //   Input_File>>hit_id>>c>>x>>c>>y>>c>>z>>c>>volume_id>>c>>layer_id>>c>>module_id;
  //   cout<<x<<" "<<y<<" "<<z<<endl;
  // }
  ifstream Input_File("event000001000-hits.csv");
  int hit,volume,layer,module;
  double x1,y1,z1;
  vector<int>volume_id,layer_id,hit_id;
  vector <double> x,y,z;
  char c;
  string s;
  Input_File>>s;
  while(Input_File.good()){
    Input_File>>hit>>c>>x1>>c>>y1>>c>>z1>>c>>volume>>c>>layer>>c>>module;
    // cout<<x<<" "<<y<<" "<<z<<endl;
    auto it1 = volume_id.emplace(volume_id.end() ,volume);
    auto it2 =  layer_id.emplace(layer_id.end()  ,layer);
    auto it3 =         x.emplace(x.end()         ,x1);
    auto it4 =         y.emplace(y.end()         ,y1);
    auto it5 =         z.emplace(z.end()         ,z1);
    auto it6 =    hit_id.emplace(hit_id.end()    ,hit);
  }

  for(int i=0; i<hit_id.size(); i++){
    cout<<hit_id[i]<<" "<<x[i]<<" "<<y[i]<<" "<<z[i]<<" "<<volume_id[i]<<" "<<layer_id[i]<<endl;
  }

  for(int i=0; i<hit_id.size(); i++){
    // cout<<hit_id[i]<<" "<<x[i]<<" "<<y[i]<<" "<<z[i]<<" "<<volume_id[i]<<" "<<layer_id[i]<<endl;
    for(int j=i+1; j<hit_id.size(); j++){
      if(volume_id[i]!=volume_id[j]  || layer_id[i]!=layer_id[j]){
        // cout<<"hi";
        double x_d = x[i]-x[j] ;
        double y_d = y[i]-y[j] ;
        double z_d = z[i]-z[j] ;
        double distance  = sqrt( x_d*x_d + y_d*y_d + z_d*z_d);
        cout<<setprecision(4)<<distance;
      }
    }
  }



  return 0;
}
