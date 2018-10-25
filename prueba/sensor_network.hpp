#ifndef SENSOR_NETWORK__HPP
#define SENSOR_NETWORK__HPP

#include <iostream>
#include "array.hpp"
#include "sensor.hpp"

using namespace std;

#define   BAD_QUERY_MSG     "BAD QUERY"
#define   UNKNOWN_ID_MSG    "UnknownID"
#define   NO_DATA_MSG       "NO DATA"
#define   DELIM             ", "

class sensorNetwork{

private:

  array <sensor> network;
  int            quantity;

public:
                    sensorNetwork();
                    sensorNetwork(array <sensor>,int);
                    sensorNetwork(const sensorNetwork &);
                    sensorNetwork(int n);
                    ~sensorNetwork();
void                process_input_file(istream &iss);
void                process_query(istream &,ostream &);
int                 get_quantity() const;
array <sensor>      get_network() const;
sensor              get_sensor(const int) const;
friend ostream & operator<<(ostream &os,const sensorNetwork & s);
int                 get_sensor_data_size(int i) const;
double              get_sensor_network_mean_instant(int in);
sensor              merge_beta(int, int &);
void				buildSegmentTrees();

};


#endif
