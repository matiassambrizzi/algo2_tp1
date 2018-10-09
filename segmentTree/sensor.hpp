#ifndef SENSOR__HPP
#define SENSOR__HPP
#include <iostream>
#include "array.hpp"
#include "dato.hpp"

using namespace std;
#define INVALID_VALUE -274

class sensor
{

private:
  string name;
  array <dato> data;

public:
                    sensor();
                    sensor(string, array<dato>);
                    sensor(const sensor &);
                    ~sensor();
  string            get_name() const;
  array <dato>    get_data() const;
  void              set_name(string);
  void              set_data(array<dato>);
  void              push_back_data(const dato);
  double            get_max_value();
  double            get_min_value();
  double            get_mean_value();
  void              print(ostream &os);
  friend ostream& operator<<(ostream&,const sensor &);
  bool              query(int, int &, double &, double &, double &, int &);
  bool            get_data_value(int pos,double &val);
};

#endif
