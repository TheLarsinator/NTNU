#include <ostream>

using namespace std;

template<typename T>
class SimpleSet{
    public:
        /** Construct empty set **/
		SimpleSet(int max)
		{
			data = new T[max];
			currentSize = 0;
			maxSize = max;
		}
        /** Destructor */
		~SimpleSet()
		{
			delete[] data;
			data = nullptr;
		}
        /** Insert i into set, return true if the element was inserted, else false **/
		bool insert(T i)
		{
			if (currentSize < maxSize && find(i) == -1)
			{
				data[currentSize] = i;
				currentSize++;
				return true;
			}
			else if (currentSize == maxSize && find(i) == -1)
			{
				//cout << "For liten, øker plassen." << endl;
				resize(currentSize+1);
				data[currentSize] = i;
				currentSize++;
				return true;
			}
			else
			{
				return false;
			}
		}

        /** Returns true if i is in the set **/
		bool exists(T i)
		{
			if (find(i) != -1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
        /** Removes i from the set, return true if an element was removed **/
		bool remove(T i)
		{
			if(find(i) < currentSize && find(i) != -1)
			{
				if (data[find(i)] == i)
				{
					int *temp = new T[maxSize];
					for (int j = 0; j < find(i); j++)
					{
						temp[j] = data[j];
					}
					for (int k = find(i) + 1; k < currentSize; k++)
					{
						temp[k - 1] = data[k];
					}
					data = temp;
					currentSize--;
					//delete[] temp;  IKKE SLETT PEKEREN; DATA BRUKER DEN!
					//temp = nullptr;
					return true;
				}
			}
			return false;
		}



		void print()
		{
			cout << "Current size: " << currentSize << endl;
			for (int i = 0; i < currentSize; i++)
			{
				cout << data[i] << endl;
			}
		}


    private:
        /** Dynamic array containing set elements **/
        T *data;
        /** Current number of elements **/
        int currentSize;
        /** Max capasity of data **/
        int maxSize;       
        
        /** Returns the index where i may be found, else an invalid index. **/
		int find(T i)
		{
			for (int a = 0; a < currentSize; a++)
			{
				if (data[a] == i)
					return a;
			}
			return -1;
		}

		/** Resizes data, superflous elements are dropped. **/
		void resize(int n)
		{
			if (currentSize > n)
			{
				currentSize = n;
			}
			T *temp = data;
			data = new T[n];
			for (int i = 0; i < n; i++)
			{
				data[i] = temp[i];
			}
			delete[] temp;
			temp = nullptr;
			maxSize = n;
		}

};