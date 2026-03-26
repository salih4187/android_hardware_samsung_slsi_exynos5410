#include "ExynosPrimaryDisplay.h"
#include "ExynosHWCModule.h"

ExynosPrimaryDisplay::ExynosPrimaryDisplay(int numGSCs, struct exynos5_hwc_composer_device_1_t *pdev) :
    ExynosOverlayDisplay(numGSCs, pdev)
{
}

int ExynosPrimaryDisplay::waitForRenderFinish(buffer_handle_t *handle, int buffers)
{
    if (mGrallocModule->FinishPVRRender(mGrallocModule, handle, buffers) < 0)
        return -1;

    return 0;
}

/* ExynosPrimaryDisplay::handleOffscreenRendering
          (hwc_layer_1 *layer,hwc_display_contents_1 *contents,
          int index)

{
  this->mHasCropSurface = false;
  if (&layer->format < 0) {
    this->mHasCropSurface = true;
  }
  if ((this->mXres) < (&layer->displayFrame->right) {
    this->mHasCropSurface = true;
  }
  if (index < contents->mXdpi - 1) {
    if (0.0f < (layer.sourceCropf) && (&layer->displayFrame->right) < (this + 8) &&
        ((contents + (index + 1) * 0x70 + 0x34) == (&layer->sourceCropf)) &&
       ((contents + (index + 1) * 0x70 + 0x4c) == (&layer->displayFrame->right))) {
      this->mForceFb = true;
    }
    if (((0.0f < (layer + 0x1c)) && (*(int *)(layer + 0x44) < *(int *)(this + 0xc))) &&
       ((*(float *)(contents + (index + 1) * 0x70 + 0x38) == *(float *)(layer + 0x1c) &&
        (*(int *)(contents + (index + 1) * 0x70 + 0x50) == *(int *)(layer + 0x44))))) {
      this->mForceFb = true;
    }
  }
}
*/

ExynosPrimaryDisplay::~ExynosPrimaryDisplay()
{
}
