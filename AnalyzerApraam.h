#ifndef ANALYZERAPRAAM_H
#define ANALYZERAPRAAM_H

#include "Analyzer.h"

class AnalyzerApraam final : public Analyzer
{
public:
    AnalyzerApraam();
    AnalyzerApraam(Logger*);
    Token getAnalysedToken() override;
};

#endif // ANALYZERAPRAAM_H
