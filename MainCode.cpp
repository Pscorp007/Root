{

  string Event_Number,Graph,s;

  cout<<"Input Event number"<<endl;
  cin>>Event_Number;
  cout<<"Enter type of graph you want"<<endl;
  cin>>Graph;

  // Graph Definitions
  HitGlobal_xy = new TGraph();
  HitGlobal_rz = new TGraph();
  // for NHit_vs_theta theta ranges from 0 to 180 degrees so 100 bins taken
  NHit_vs_theta_Histogram = new TH1D("NHit_vs_theta_Histogram", "NHit_vs_theta;Polar Angle(Theta)[Degrees];Number of Hits",  100 , 0,180);
  // for NHitPair_vs_dist Max distance is approx 5k-6k so 100 bins in range
  NHitPair_vs_dist = new TH1D("NHitPair_vs_dist","NHitPair_vs_dist;Distance;Number of Pairs",100,0,6000);




  if(  Graph == "HitGlobal_xy"  ){


    HitGlobal_xy->SetTitle("Measured Hit Position Projected to x-y Plane;X(mm);Y(mm)");

    ifstream Input_File("event"+Event_Number+"-hits.csv");//input file

    int hit,volume,layer,module;
    double x,y,z;
    char c;
    Input_File>>s;//for ignoring first line which consists comma seprated strings

    // Main Calculation
    while(Input_File.good()){
      Input_File>>hit>>c>>x>>c>>y>>c>>z>>c>>volume>>c>>layer>>c>>module;
      HitGlobal_xy->SetPoint(hit,x,y);
    }

    //plot
    HitGlobal_xy->Draw("AP");


  }
  else if(  Graph == "HitGlobal_rz"  ){


    HitGlobal_rz->SetTitle("Measured Hit Position Projected to r-z Plane;Z(mm);R(mm)");
    ifstream Input_File("event"+Event_Number+"-hits.csv");// input file

    int hit,volume,layer,module;
    double x,y,z;
    char c;
    Input_File>>s;//ignoring first line of file

    //Main Calculation
    while(Input_File.good()){
      Input_File>>hit>>c>>x>>c>>y>>c>>z>>c>>volume>>c>>layer>>c>>module;
      double r = sqrt(  (  x*x  )  +  (  y*y  )  ); //Calculation of R for plot
      HitGlobal_rz->SetPoint(hit,z,r);
    }

    //plot
    HitGlobal_rz->Draw("AP");


  }
  else if(  Graph == "NHit_vs_theta"  ){


    ifstream Input_File("event"+Event_Number+"-particles.csv");//input file

    string particle_id;
    int q,j=0;
    double vx,vy,vz,px,py,pz,nhits;
    char c;
    Input_File>>s;

    //Main Calculation
    while(Input_File.good()){
      Input_File>>particle_id>>c>>vx>>c>>vy>>c>>vz>>c>>px>>c>>py>>c>>pz>>c>>q>>c>>nhits;
      double theta = acos(vz/(sqrt(  (  vx*vx  )  +  (  vy*vy  )  +  (  vz*vz  )  ))); // Calculationof theta using inverseCos formula
      theta = theta*(180 / 3.141592);//conversion to degrees
      if(isnan(theta))continue; // for cases where theta tends to nan
      NHit_vs_theta_Histogram->Fill(theta);
    }

    // plot
    NHit_vs_theta_Histogram->Draw();


  }
  else if(  Graph == "NHitPair_vs_dist"  ){


    ifstream Input_File("event"+Event_Number+"-hits.csv");//Input file

    int hit,volume,layer,module;
    double x,y,z;
    char c;
    vector<int>volume_id,layer_id,hit_id;
    vector <double> cx,cy,cz;
    Input_File>>s;

    // Storing all the data in vector form
    while(Input_File.good()){
      Input_File>>hit>>c>>x>>c>>y>>c>>z>>c>>volume>>c>>layer>>c>>module;
      auto it1 = volume_id.emplace(volume_id.end() ,volume);
      auto it2 =  layer_id.emplace(layer_id.end()  ,layer);
      auto it3 =         cx.emplace(cx.end()         ,x);
      auto it4 =         cy.emplace(cy.end()         ,y);
      auto it5 =         cz.emplace(cz.end()         ,z);
      auto it6 =    hit_id.emplace(hit_id.end()    ,hit);
    }

    // Main Calculation for each pair of hits
    for(int i=0; i<hit_id.size(); i++){
      for(int j=i+1; j<hit_id.size(); j++){
        if(volume_id[i]!=volume_id[j]  || layer_id[i]!=layer_id[j]){
          double x_d = cx[i]-cx[j] ;
          double y_d = cy[i]-cy[j] ;
          double z_d = cz[i]-cz[j] ;
          double distance  = sqrt( x_d*x_d + y_d*y_d + z_d*z_d); // distance using distance formula
          NHitPair_vs_dist->Fill(distance);
        }
      }

    }
    // plot
    NHitPair_vs_dist->Draw();

  }

}
