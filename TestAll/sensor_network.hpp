#ifndef SENSOR_NETWORK__HPP
#define SENSOR_NETWORK__HPP

#include <iostream>
#include "array.hpp"
#include "sensor.hpp"
#include "node.hpp"
#include "segmentTree.hpp"
#include "errors.hpp"
#include "types.hpp"

using namespace std;

#define   BAD_QUERY_MSG     "BAD QUERY"
#define   UNKNOWN_ID_MSG    "UnknownID"

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
status_t                process_input_file(istream &iss);
void                process_query(istream &,ostream &);
void                process_query_tree(istream &,ostream &);
int                 get_quantity() const;
array <sensor>      get_network() const;
sensor              get_sensor(const int) const;
friend ostream & operator<<(ostream &os,const sensorNetwork & s);
int                 get_sensor_data_size(int i) const;
dato              get_sensor_network_mean_instant(int in);
sensor              merge_beta(int, int &);
void	              buildSegmentTrees();
int                 sizeRound(int lengthData);
};


#endif
