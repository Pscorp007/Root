{
  ifstream input_File("data.csv");
  int s3,s4;
  while(input_File.good()){
    getline(input_File,s3,',');
    getline(input_File,s4,',');
    cout<<s3<<" "<<s4<<"\n";
  }
}
