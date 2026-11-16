#pragma once


template<class t>
class PriorityQueue
{
private:
	int count;
	t** data;
	int size;

public:
	~PriorityQueue();
	PriorityQueue(int size) {
		data = new t * [size];
		this->size = size;
		count = 0;
	};
	void Insert(t* item);
	bool IsEmpty();
	bool IsFull();
	t* PeakMin();
	t* Remove();
	int Size();
};


template<class t>
PriorityQueue<t>::~PriorityQueue()
{
	for (int i = 0; i < count; i++) {
		delete data[i];
	}
	delete[] data;
}

template<class t>
void PriorityQueue<t>::Insert(t* item)
{
    if (IsFull())
        return;

    int j = count - 1;

    while (j >= 0 && *item > *data[j])
    {
        data[j + 1] = data[j];
        j--;
    }

    data[j + 1] = item;
    count++;
}
template<class t>
bool PriorityQueue<t>::IsEmpty()
{
	return count == 0;
}
template<class t>
bool PriorityQueue<t>::IsFull()
{
	return count == size;
}
template<class t>
t* PriorityQueue<t>::PeakMin()
{
	return count[*data - 1];
}
template<class t>
t* PriorityQueue<t>::Remove()
{
	return data[--count];
}
template<class t>
int PriorityQueue<t>::Size()
{
	return count;
}



