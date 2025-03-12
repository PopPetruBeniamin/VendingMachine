//
// Created by Usuario on 19/05/2024.
//

#ifndef LAB_9_10_FINAL_FINAL_COLLECTION_H
#define LAB_9_10_FINAL_FINAL_COLLECTION_H

#include <iostream>
#include "../DynamicVector/DynamicVector.h"

template<typename TElem>
class Collection {
private:
    DynamicVector<TElem> elements;
    DynamicVector<int> nrOccurrences;
    void reorder();
public:
    Collection() = default;
    ~Collection() = default;

    void add(TElem e){
        bool exist = search(e);

        if(exist){
            for(int i = 0 ; i < elements.size() ; i++)
                if(e == elements[i])
                    nrOccurrences[i]++;
        }
        else{
            elements.push_back(e);
            nrOccurrences.push_back(1);
        }
        reorder();
    }

    bool remove(TElem e){
        bool exist = false;
        int position;

        //This function check if the element e exist in the DynamicVector elements and save the position
        for(int i = 0 ; i < elements.size() ; i++){
            if(elements[i] == e){
                exist = true;
                position = i;
            }
        }

        if(exist){
            if(nrOccurrences[position] > 1){
                nrOccurrences[position]--;
            } else {
                elements.pop(position);
                nrOccurrences.pop(position);
            }
            reorder();
            return true;
        }
        reorder();
        return false;
    }

    bool search(TElem e){
        for (int i = 0; i < elements.size(); i++)
            if (e == elements[i])
                return true;
        return false;
    }

    int size(){
        return elements.size();
    }

    int nroccurrences(TElem e){
        for(int i = 0 ; i < elements.size() ; i++)
            if(elements[i] == e)
                return nrOccurrences.getAt(i);
        return 0;
    }

    TElem getAt(int position) const{
        if( (position >= 0) && (position < elements.size()) )
            return elements.getAt(position);
        else
            throw std::invalid_argument("H! ");
    }

    DynamicVector<TElem>& getAllElements(){
        return this->elements;
    }

    TElem& operator[](int i) {
        if(i >= 0 && i < elements.size())
            return elements[i];
    }

    const TElem& operator[](int i) const {
        if(i >= 0 && i < elements.size())
            return elements[i];
    }

    /*DynamicVector<int> getAllOccurrences(){
        return this->nrOccurrences;
    }*/
};

template<typename TElem>
void Collection<TElem>::reorder() {
    TElem aux1;
    int aux2;
    int size = elements.size();

    for(int i = 0; i < size; i++){
        for(int j = i; j < size; j++)
            if(elements[i] < elements[j]){
                aux1 = elements[i];
                elements[i] = elements[j];
                elements[j] = aux1;

                aux2 = nrOccurrences[i];
                nrOccurrences[i] = nrOccurrences[j];
                nrOccurrences[j] = aux2;
            }
    }
}

#endif //LAB_9_10_FINAL_FINAL_COLLECTION_H
