#pragma once
using namespace std;

#if 0
template<typename K, typename V, int N>
class KVList {
	K k[N];
	V v[N];
	size_t count = 0;
public:
	KVList() {
	
	}//									
	size_t size() const {
		return count;
	}
	const K& key(int i) const {
		if (i < count) {
			return k[i];
		}
	}

	const V& value(int i) const {
		if (i < count) {
			return v[i];
		}//	
	}

	KVList& add(const K& kk, const V& vv) {
		if (count < N) {
			k[count] = kk;
			v[count] = vv;
			count++;
		}
		return *this;
	}
	int find(const K& kk) const {
		for (size_t i = 0; i < count; i++) {
			if (kk == k[i]) {
				return i;
			}
		}
		return 0;
	}
	KVList& replace(int i, const K& kk, const V& vv) {
		if (i < count) {
			k[i] = kk;
			v[i] = vv;
		}
		return *this;
	}

};

#endif
#// makepair
#if 1
template<typename K, typename V, int N>
class KVList {
	pair<K,V>data[N];
	size_t count = 0;
public:
	KVList() {

	}//									
	size_t size() const {
		return count;
	}
	const K& key(int i) const {
		if (i < count) {
			return data[i].first;
		}
	}

	const V& value(int i) const {
		if (i < count) {
			return data[i].second;
		}//	
	}

	KVList& add(const K& kk, const V& vv) {
		if (count < N) {
			data[count].first = kk;
			data[count].second = vv;
			count++;
		}
		return *this;
	}
	int find(const K& kk) const {
		for (size_t i = 0; i < count; i++) {
			if (kk == data[i].first) {
				return i;
			}
		}
		return 0;
	}
	KVList& replace(int i, const K& kk, const V& vv) {
		if (i < count) {
			//data[i].first = kk;
			//data[i].second = vv;
			data[i] = make_pair(kk, vv);
		}
		return *this;
	}
};
#endif 
