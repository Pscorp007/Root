{

  c = new TCanvas("c","My Canvas for Histograms",1000,500);
  c->Divide(2,2);


  h1 = new TH1D("h1", "Histogram1;x;y",   5, 0, 5); //T-always there, H-histogram 1-one dimensional , D-doubles(could also be integers)
  //  5 bins going from 0 to 5
  h2 = new TH1D("h2","Big Bins",          3,0,10);
  h3 = new TH1D("h3","Normal Bins",       100,0,10);
  h4 = new TH1D("h4","Way too many Bins", 1e5,0,10);



  c->cd(1);
  h1->Fill(3);
  h1->Fill(2.00000004);
  h1->Fill(2);
  for(int i=0; i<1e4; i++){
    double x = gRandom->Gaus(5,2);
    h1->Fill(x);
    h2->Fill(x);
    h3->Fill(x);
    h4->Fill(x);
  }
  h1->SetMinimum(0);
  h1->SetStats(0); // to remove that box on top right showing details
  h1->Draw();


  c->cd(2);
  h2->Draw();
  c->cd(3);
  h3->Draw();
  c->cd(4);
  h4->Draw();

}


// Intro to histograms
/*
type TH1D::TH1D( tab
when we didn't declared any histo then we write like that

running this program too many times may give you an error in that case you have to
exit the root by typing   .q   to quit

normal bins -  no of bins  = sqrt of no of things

tip:   h = new TH1D("h","roll die",6, 0.5,6.5); 6 bins are there so start from 0.5 to 6.5 so that
the first histogram is centred at 1

gRandom->Integer(6); will give random number between 0-5


*/
