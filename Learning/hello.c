{

  c1 = new TCanvas("c1","My canvas ",1000,500); // name,title,windowWidth,windowheight
  c1->Divide(3,1); // this has two arguments (no of columns,no or rows)

  c1->cd(1);// this is like change directory 1 implies panel 1
  f1 = new TF1("f1","sin(x)",0,5);
  f1->SetLineColor(kBlue+2);
  f1->SetTitle("My fuction; X-Axix; Y-Axis");
  f1->Draw();

  c1->cd(2);// second panel
  f2 = new TF1("f2","cos(x)",0,5);
  f2->SetLineColor(kRed);
  f2->SetTitle("My other fuction; X; Y");
  // f2->Draw("SAME");   // you need to write same parameter to draw on the smae grid
  // else it will first draw 1st one (sine) then second so first dissapears
  //this is after creating panels
  f2->Draw(); // you do not write same parameter since you are in panel 2

  c1->cd(3);
  f3 = new TF2("f3","10*cos(x)*sin(y)",-3,3,0,10);// TF2 means two dimensional graph now xgoes from -3 to 3 and y from 0 to 10
  // f3->Draw();
  f3->SetTitle("Surface;x;y");
  f3->Draw("surf2");
}








// in the terminal write .x hello.c to run a file  (x means execute)
/*
f = new TF1(  then press tab
TF1::Set   then press tab
c1 = new TCanvas(  press tab to see what you need to write in syntax
c1->Divide( tab

for f3 right click on graph click set draw option type surf1 or surf2 then ok
to get 3d view or you can directly type what you want in f3->Draw("here it goes");

*/
