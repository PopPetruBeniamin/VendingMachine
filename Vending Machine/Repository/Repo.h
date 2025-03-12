//
// Created by Usuario on 19/05/2024.
//

#ifndef LAB_9_10_FINAL_FINAL_REPO_H
#define LAB_9_10_FINAL_FINAL_REPO_H

#include "Collection/Collection.h"

template <typename TElem>
class Repo{
protected:
    Collection<TElem> repoElements;
public:
    Repo() = default;
    virtual ~Repo() = default;

    virtual void addElement(const TElem& givenElement){
        repoElements.add(givenElement);
    }

    virtual void removeElement(const TElem& givenElement){
        repoElements.remove(givenElement);
    }

    virtual void updateElement(const TElem& searchedElement, const TElem& givenElement){
        bool theElemExist = repoElements.search(searchedElement);

        if(theElemExist){
            for(int i = 0; i < repoElements.size(); i++)
                if(repoElements[i] == searchedElement)
                    repoElements[i] = givenElement;
        }
    }

    Collection<TElem>& getElements() {
        return this->repoElements;
    }
};


#endif //LAB_9_10_FINAL_FINAL_REPO_H
