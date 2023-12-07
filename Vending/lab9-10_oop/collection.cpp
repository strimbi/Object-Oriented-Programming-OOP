#include "collection.h"

Collection::Collection()
{
    elements = new TElem[5];
    elements[0] = 2;
    elements[1] = 5;
    elements[2] = 7;
    occurrences = new int[5];
    occurrences[0] = 4;
    occurrences[1] = 9;
    occurrences[2] = 5;
    distinctelements = 3;
    capacity = 5;
}

void Collection::add(TElem elem) 
{
    bool exist = false;
    int position;
    for (int i = 0; i < distinctelements; i++)
        if (elem == elements[i]) {
            exist = true;
            position = i;
        }

    if (exist)
        occurrences[position] = occurrences[position] + 1;
    else {
        if (distinctelements + 1 > capacity) {
            capacity *= 2;
            TElem* tmp = new TElem[capacity];
            for (int i = 0; i < distinctelements; ++i) {
                tmp[i] = elements[i];
            }
            delete[] elements;
            elements = tmp;
            int* tmp2 = new int[capacity];
            for (int i = 0; i < distinctelements; ++i) {
                tmp2[i] = occurrences[i];
            }
            delete[] occurrences;
            occurrences = tmp2;

        }
        elements[distinctelements] = elem;
        occurrences[distinctelements] = 1;
        distinctelements++;
    }
}

bool Collection::remove(TElem elem)
{
    bool exist = false;
    int position;
    for (int i = 0; i < distinctelements; i++) 
    {
        if (elem == elements[i]) {
            exist = true;
            position = i;
        }
    }

    if (exist)
    {
        if (occurrences[position] > 1) 
        {
            occurrences[position]--;
        }
        else
        {
            for (int i = position; i < distinctelements - 1; i++) 
            {
                elements[i] = elements[i + 1];
                occurrences[i] = occurrences[i + 1];
            }
            distinctelements--;
        }
        return true;
    }
    return false;
}

bool Collection::search(TElem elem)
{
    for (int i = 0; i < distinctelements; i++)
        if (elem == elements[i])
            return true;
    return false;
}

int Collection::size() 
{
    return distinctelements;
}

int Collection::nroccurrences(TElem elem) 
{
    for (int i = 0; i < distinctelements; i++)
        if (elements[i] == elem)
            return occurrences[i];
    return 0;
}

void Collection::destroy()
{
    delete[] elements;
    delete[] occurrences;
    distinctelements = 0;
}

int Collection::getAt(int position) 
{
    return elements[position];
}
