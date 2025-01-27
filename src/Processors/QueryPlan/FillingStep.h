#pragma once
#include <Processors/QueryPlan/ITransformingStep.h>
#include <Core/SortDescription.h>
#include <Core/InterpolateDescription.h>

namespace DB
{

/// Implements modifier WITH FILL of ORDER BY clause. See FillingTransform.
class FillingStep : public ITransformingStep
{
public:
    FillingStep(const DataStream & input_stream_, SortDescription sort_description_, InterpolateDescriptionPtr interpolate_description_);

    String getName() const override { return "Filling"; }

    void transformPipeline(QueryPipelineBuilder & pipeline, const BuildQueryPipelineSettings &) override;

    void describeActions(JSONBuilder::JSONMap & map) const override;
    void describeActions(FormatSettings & settings) const override;

    const SortDescription & getSortDescription() const { return sort_description; }

private:
    SortDescription sort_description;
    InterpolateDescriptionPtr interpolate_description;
};

}
