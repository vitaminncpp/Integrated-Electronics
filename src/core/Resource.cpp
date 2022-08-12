#include "Resource.h"

using namespace core::resources;


Resource::~Resource() {

}

interface::gfx::Image *Resource::GetAndImage() {
    return this->andImage;
}
