int qhist(string inputfile="mysample.txt", bool autoSearch=true,  int bins=100, double xmin=-1, double xmax=1) {
  vector<double>* data = new vector<double>;

  // reading file
  double min, max, d;
  ifstream fin( inputfile.c_str() );
  fin >> d;
  if(!fin.good()) return 0;
  min = max = d;
  data->push_back(d);
  int i=1;
  for(;;++i) {
    fin >> d;
    if(!fin.good()) break;
    data->push_back(d);
    if(d>max) max=d;
    if(d<min) min=d;
  }
  cout << "Read " << i << " lines" << endl;

  // set auto range
  if(autoSearch) {
    double xrange = max - min;
    xmin = min - 0.1 * xrange;
    xmax = max + 0.1 * xrange;
  }

  // making histogram
  TH1D *hist = new TH1D("hist","",bins,xmin,xmax);
  for( double& d : *data ) {
    hist->Fill(d);
  }
  hist->Draw();

  return 0;
}