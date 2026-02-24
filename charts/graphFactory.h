#pragma once
#include "abstractGraph.h"
#include "barChart.h"
#include "lineChart.h"
#include "pieChart.h"
#include <memory>

enum class GraphType { Bar, Line, Pie };

class GraphFactory {
public:
    static std::unique_ptr<AbstractGraph> createGraph(GraphType type, QWidget* parent = nullptr) {
        switch(type) {
            case GraphType::Bar: return std::make_unique<BarChart>(parent);
            case GraphType::Line: return std::make_unique<LineChart>(parent);
            case GraphType::Pie: return std::make_unique<PieChart>(parent);
        }
        return nullptr;
    }
};
