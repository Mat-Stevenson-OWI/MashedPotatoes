#pragma once

#include "CoreMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(LogMashedPotatoes, Verbose, All);

#define LOG_VERYVERBOSE(Format, ...) UE_LOG(LogMashedPotatoes, VeryVerbose, TEXT(Format), ##__VA_ARGS__);
#define LOG_VERBOSE(Format, ...) UE_LOG(LogMashedPotatoes, Verbose, TEXT(Format), ##__VA_ARGS__);
#define LOG_INFO(Format, ...) UE_LOG(LogMashedPotatoes, Log, TEXT(Format), ##__VA_ARGS__);
#define LOG_DISPLAY(Format, ...) UE_LOG(LogMashedPotatoes, Display, TEXT(Format), ##__VA_ARGS__);
#define LOG_WARNING(Format, ...) UE_LOG(LogMashedPotatoes, Warning, TEXT(Format), ##__VA_ARGS__);
#define LOG_ERROR(Format, ...) UE_LOG(LogMashedPotatoes, Error, TEXT(Format), ##__VA_ARGS__);
#define LOG_FATAL(Format, ...) UE_LOG(LogMashedPotatoes, Fatal, TEXT(Format), ##__VA_ARGS__);

#define CLOG_VERYVERBOSE(Cond, Format, ...) UE_CLOG(Cond, LogMashedPotatoes, VeryVerbose, TEXT(Format), ##__VA_ARGS__);
#define CLOG_VERBOSE(Cond, Format, ...) UE_CLOG(Cond, LogMashedPotatoes, Verbose, TEXT(Format), ##__VA_ARGS__);
#define CLOG_INFO(Cond, Format, ...) UE_CLOG(Cond, LogMashedPotatoes, Log, TEXT(Format), ##__VA_ARGS__);
#define CLOG_DISPLAY(Cond, Format, ...) UE_CLOG(Cond, LogMashedPotatoes, Display, TEXT(Format), ##__VA_ARGS__);
#define CLOG_WARNING(Cond, Format, ...) UE_CLOG(Cond, LogMashedPotatoes, Warning, TEXT(Format), ##__VA_ARGS__);
#define CLOG_ERROR(Cond, Format, ...) UE_CLOG(Cond, LogMashedPotatoes, Error, TEXT(Format), ##__VA_ARGS__);
#define CLOG_FATAL(Cond, Format, ...) UE_CLOG(Cond, LogMashedPotatoes, Fatal, TEXT(Format), ##__VA_ARGS__);