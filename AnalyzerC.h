#ifndef ANALYZERC_H
#define ANALYZERC_H

#include "Analyzer.h"

class AnalyzerC final : public Analyzer
{
public:
    AnalyzerC();
    Token getAnalysedToken() override;
};

#endif // ANALYZERC_H
