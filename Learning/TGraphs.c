{
  c = new TCanvas("c","Intro to TGraphs",1000,500);
  c->Divide(2,1);

  c->cd(1);
  g1 = new TGraph("file.csv");
  g1->SetTitle("Data plot with Tgraph;x;y");
  g1->Draw("ALP");

  c->cd(2);
  g2 = new TGraph(); // line 1 define g2;
  for(int i=0; i<10; i++){
    g2->SetPoint(i,i,i*i);
  }
  g2->Draw("APC");


}









//Introduction to graphs
/*
type g = new TGraph( tab
ALP -  axis line points and c for curve
by default points are infinitisimally small
go to edit-style-selectmarker..then apply else
g->SetMarkerStyle(21); the numbers can be known by click view-markers

canvas 2

type g2->SetPoint(tab     Note: before you can writhe this in terminal you have to define
g2 in order to not get error so write  line 1 to define g2

g2->SetPoint(0,1,2);   // (i,x,y) i-just like array we have point numbers,then x,y as coordinates


*/
