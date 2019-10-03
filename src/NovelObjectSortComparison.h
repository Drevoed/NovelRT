//
// Created by matth on 30/03/2019.
//

#ifndef NOVELRT_NOVELOBJECTSORTCOMPARISON_H
#define NOVELRT_NOVELOBJECTSORTCOMPARISON_H

#include "NovelObject.h"
namespace NovelRT {
struct NovelObjectSortComparison {
public:
  inline bool operator()(NovelObject* lhs, NovelObject* rhs) const {
    return lhs->getOrderInLayer() < rhs->getOrderInLayer();
  }
};
}
#endif //NOVELRT_NOVELOBJECTSORTCOMPARISON_H