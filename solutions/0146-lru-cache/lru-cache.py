# -*- coding:utf-8 -*-


# Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.
#
# get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
# put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
#
# The cache is initialized with a positive capacity.
#
# Follow up:
# Could you do both operations in O(1) time complexity?
#
# Example:
#
#
# LRUCache cache = new LRUCache( 2 /* capacity */ );
#
# cache.put(1, 1);
# cache.put(2, 2);
# cache.get(1);       // returns 1
# cache.put(3, 3);    // evicts key 2
# cache.get(2);       // returns -1 (not found)
# cache.put(4, 4);    // evicts key 1
# cache.get(1);       // returns -1 (not found)
# cache.get(3);       // returns 3
# cache.get(4);       // returns 4
#
#
#  
#


import collections as co
class LRUCache(object):
    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.n = capacity
        self.V = {} # key -> value
        self.N = {} # key -> next key used
        self.P = {} # key -> prev key used
        self.head = None # mru key
    
    def fuse(self,key): # link neighbors
        n = self.N[key]
        p = self.P[key]
        self.N[p]=n
        self.P[n]=p
    
    def push(self,key): # insert at head
        if not self.head:
            self.head = key
            self.P[key] = key
            self.N[key] = key
            return
        if self.head==key:
            return
        if key in self.N:
            self.fuse(key)
        lru = self.N[self.head]
        self.N[key] = lru
        self.P[key] = self.head
        self.N[self.head] = key
        self.P[lru] = key
        self.head = key
    
    def remove(self,key):
        self.fuse(key)
        del self.V[key]
        del self.N[key]
        del self.P[key]
    
    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key not in self.V:
            return -1
        self.push(key)
        return self.V[key]
        

    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: void
        """
        self.V[key]=value
        self.push(key)
        if len(self.V)>self.n:
            self.remove(self.N[self.head])
            
    def printobj(self):
        print(self.V,self.T,self.K)
        


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
