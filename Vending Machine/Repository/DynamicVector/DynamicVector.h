//
// Created by Usuario on 19/05/2024.
//

#ifndef LAB_9_10_FINAL_FINAL_DYNAMICVECTOR_H
#define LAB_9_10_FINAL_FINAL_DYNAMICVECTOR_H

#include <stdexcept>

template<typename TElem>
class DynamicVector{
private:
    int capacity{};
    int nrElems{};
    TElem* elems;   //vectorul de elemente

    void resize(){
        auto * aux = new TElem [2*capacity];
        for(int i=0; i<capacity; i++)
            aux[i] = this->elems[i];
        delete[] elems;
        this->elems = aux;
        this->capacity = 2*capacity;
    }

public:
    DynamicVector(){
        this->capacity = 1;
        this->nrElems = 0;
        this->elems = new TElem[this->capacity];
    }

    explicit DynamicVector(int capacitate){
        if(capacitate > 0){
            this->elems = new TElem [capacitate];
            this->nrElems = 0;
            this->capacity = capacitate;
        }
        else{
            this->capacity = 1;
            this->nrElems = 0;
            this->elems = new TElem[this->capacity];
        }
    }

    DynamicVector(const DynamicVector& other){
        if(this != &other){
            delete [] elems;
            this->capacity = other.capacity;
            this->nrElems = other.nrElems;
            this->elems = new TElem[this->capacity];
            for (int i = 0; i < this->nrElems; ++i) {
                this->elems[i] = other.elems[i];
            }
        }
    }

    ~DynamicVector(){
        delete[] this->elems;
    }

    //Get
    [[nodiscard]] TElem getAt(int i) const{
        if(i >= 0 && i < nrElems)
            return this->elems[i];
        else
            throw std::out_of_range("Index out of range");
    }

    void push_back(TElem e){
        //this->elems[nrElems] = e;
        //this->nrElems++;
        if(nrElems==capacity){
            resize();
        }
        this->elems[nrElems++] = e;
    }

    void pop_back(){
        if (nrElems > 0)
            nrElems--;
    }

    void pop(int position){
        for(int i = position; i < nrElems - 1 ; i++)
            elems[i] = elems[i + 1];
        nrElems--;
    }

    [[nodiscard]] int size() const{
        return this->nrElems;
    }

    TElem& operator[](int i) {
        if(i >= 0 && i < nrElems)
            return elems[i];
    }

    const TElem& operator[](int i) const {
        if(i >= 0 && i < nrElems)
            return elems[i];
    }


    DynamicVector& operator=(const DynamicVector& other) {
        if (this != &other) {
            delete[] this->elems;

            this->capacity = other.capacity;
            this->nrElems = other.nrElems;
            this->elems = new TElem[this->capacity];
            for (int i = 0; i < this->nrElems; ++i) {
                this->elems[i] = other.elems[i];
            }
        }
        return *this;
    }
};

#endif //LAB_9_10_FINAL_FINAL_DYNAMICVECTOR_H

/*
 #include <stdexcept>

template<typename TElem>
class DynamicVector{
private:
    int capacity{};
    int nrElems{};
    TElem* elems;   //vectorul de elemente

    void resize(){
        auto * aux = new TElem [2*capacity];
        for(int i=0; i<capacity; i++)
            aux[i] = this->elems[i];
        delete[] elems;
        this->elems = aux;
        this->capacity = 2*capacity;
    }

public:
    DynamicVector(){
        this->capacity = 1;
        this->nrElems = 0;
        this->elems = new TElem[this->capacity];
    }

    explicit DynamicVector(int capacitate){
        if(capacitate > 0){
            this->elems = new TElem [capacitate];
            this->nrElems = 0;
            this->capacity = capacitate;
        }
        else{
            this->capacity = 1;
            this->nrElems = 0;
            this->elems = new TElem[this->capacity];
        }
    }

    DynamicVector(const DynamicVector& other){
        if(this != &other){
            delete [] elems;
            this->capacity = other.capacity;
            this->nrElems = other.nrElems;
            this->elems = new TElem[this->capacity];
            for (int i = 0; i < this->nrElems; ++i) {
                this->elems[i] = other.elems[i];
            }
        }
    }

    ~DynamicVector(){
        //delete[] this->elems;
    }

    //Get
    [[nodiscard]] TElem getAt(int i) const{
        if(i >= 0 && i < nrElems)
            return this->elems[i];
        else
            throw std::out_of_range("Index out of range");
    }

    void push_back(TElem e){
        //this->elems[nrElems] = e;
        //this->nrElems++;
        if(nrElems==capacity){
            resize();
        }
        this->elems[nrElems++] = e;
    }

    void pop_back(){
        if (nrElems > 0)
            nrElems--;
    }

    void pop(int position){
        for(int i = position; i < nrElems - 1 ; i++)
            elems[i] = elems[i + 1];
        nrElems--;
    }

    [[nodiscard]] int size() const{
        return this->nrElems;
    }

    TElem& operator[](int i) {
        if(i >= 0 && i < nrElems)
            return elems[i];
    }

    const TElem& operator[](int i) const {
        if(i >= 0 && i < nrElems)
            return elems[i];
    }


    DynamicVector& operator=(const DynamicVector& other) {
        if (this != &other) {
            delete[] this->elems;

            this->capacity = other.capacity;
            this->nrElems = other.nrElems;
            this->elems = new TElem[this->capacity];
            for (int i = 0; i < this->nrElems; ++i) {
                this->elems[i] = other.elems[i];
            }
        }
        return *this;
    }
};

 */

/*
 #include <stdexcept>
#include <vector>

template<typename TElem>
class DynamicVector{
private:
    std::vector<TElem> elems;

public:
    DynamicVector() = default;

    explicit DynamicVector(int capacitate){
        if(capacitate > 0){
            elems.reserve(capacitate);
        }
    }

    DynamicVector(const DynamicVector& other){
        elems = other.elems;
    }

    ~DynamicVector() = default;

    //Get
    [[nodiscard]] TElem getAt(int i) const{
        if(i >= 0 && i < elems.size())
            return this->elems[i];
        else
            throw std::out_of_range("Index out of range");
    }

    void push_back(TElem e){
        //this->elems[nrElems] = e;
        //this->nrElems++;
        elems.push_back(e);
    }

    void pop_back(){
        elems.pop_back();
    }

    void pop(int position){
        for(int i = position; i < elems.size() ; i++)
            elems[i] = elems[i + 1];
        elems.pop_back();
    }

    [[nodiscard]] int size() const{
        return elems.size();
    }

    TElem& operator[](int i) {
        if(i >= 0 && i < elems.size())
            return elems[i];
    }

    const TElem& operator[](int i) const {
        if(i >= 0 && i < elems.size())
            return elems[i];
    }


    DynamicVector& operator=(const DynamicVector& other) {
        if (this != &other) {
            elems = other.elems;
        }
        return *this;
    }
};

 */