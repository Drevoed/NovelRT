// Copyright © Matt Jones and Contributors. Licensed under the MIT Licence (MIT). See LICENCE.md in the repository root for more information.
#include <stdint.h>
#include "Audio/NrtAudioService.h"
#include "NrtInteropUtils.h"
#include "Input/NrtInteractionService.h"
#include "Input/NrtKeyStateFrameChangeLog.h"
#include "Timing/NrtTimestamp.h"
#include "DotNet/NrtRuntimeService.h"
#include "Utilities/NrtCommonEvents.h"
#include "Graphics/NrtRenderingService.h"
#include "NrtDebugService.h"

#ifndef NOVELRT_INTEROP_NOVELRUNNER_H
#define NOVELRT_INTEROP_NOVELRUNNER_H

#ifdef __cplusplus
extern "C" {
#endif

  typedef struct NovelRunnerHandle* NrtNovelRunner;

  NrtNovelRunner Nrt_NovelRunner_create(int displayNumber);
  NrtNovelRunner Nrt_NovelRunner_createCustom(int displayNumber, const char* windowTitle, uint32_t targetFrameRate);
  int32_t Nrt_NovelRunner_runNovel(NrtNovelRunner runner);
  int32_t Nrt_NovelRunner_destroy(NrtNovelRunner runner);

  int32_t Nrt_NovelRunner_getAudioService(NrtNovelRunner runner, NrtAudioService* outputService);
  int32_t Nrt_NovelRunner_getInteractionService(NrtNovelRunner runner, NrtInteractionService* outputService);
  int32_t Nrt_NovelRunner_getWindowingService(NrtNovelRunner runner, NrtWindowingService* outputService);
  int32_t Nrt_NovelRunner_getRuntimeService(NrtNovelRunner runner, NrtRuntimeService* outputService);
  int32_t Nrt_NovelRunner_getRenderer(NrtNovelRunner runner, NrtRenderingService* outputService);
  int32_t Nrt_NovelRunner_getDebugService(NrtNovelRunner runner, NrtDebugService* outputService);

  int32_t Nrt_NovelRunner_addUpdate(NrtNovelRunner runner, void(*func)(NrtTimestamp));
  int32_t Nrt_NovelRunner_addSceneConstructionRequested(NrtNovelRunner runner, void(*func)());
  int32_t Nrt_NovelRunner_getUpdateEvent(NrtNovelRunner runner, NrtUtilitiesEventWithTimestamp* outputEvent);
  int32_t Nrt_NovelRunner_getSceneConstructionEvent(NrtNovelRunner runner, NrtUtilitiesEvent* outputEvent);

#ifdef __cplusplus
}
#endif

#endif // NOVELRT_INTEROP_NOVELRUNNER_H
