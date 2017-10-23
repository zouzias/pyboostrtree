#!/usr/bin/env python

from boostrtrees import RTree
import numpy as np
import time
import pandas as pd

df = pd.read_csv('AIS2009.csv.gz', delimiter=';')
locs = df[['Longitude', 'Latitude', 'MMSI_Number']].astype(np.double).as_matrix().copy(order='C')

rtree = RTree()

start = time.time()
print("Tree size: {}".format(rtree.size()))
rtree.insert_points(locs)
print("Tree size: {}".format(rtree.size()))
end = time.time()

start_knn = time.time()
print('Start knn searches')
for l in range(locs.shape[0]):
    knn = rtree.knn(locs[l, 0], locs[l, 1], 3)

print('End of knn searches')
end_knn = time.time()

print("Indexing time: {}".format(end - start))
print("knn time: {}".format(end_knn - start_knn))

