#include "DwarfElephantPicewiseFunction.h"

registerMooseObject("DwarfElephantApp", DwarfElephantPicewiseFunction);

template <>
InputParameters
validParams<DwarfElephantPicewiseFunction>()
{
  InputParameters params = validParams<Function>();
  params.addClassDescription("This functions allow the combination of several function via if conditions.");
  params.addRequiredParam<std::vector<FunctionName>>("functions", "The functions.");
  params.addRequiredParam<std::vector<Real>>("thresholds", "Thresholds for the if conditions");
  return params;
}

DwarfElephantPicewiseFunction::DwarfElephantPicewiseFunction(const InputParameters & parameters)
  : Function(parameters),
  _thresholds(getParam<std::vector<Real>>("thresholds"))
{
  // if(_thresholds.size()!=3)
  //   mooseError("Thresholds need to have a size of three.");
  const std::vector<FunctionName> & _names = getParam<std::vector<FunctionName>>("functions");
  _funcs.resize(_names.size());

  for(unsigned int i = 0; i< _names.size(); i++)
    _funcs[i] = &_mci_feproblem.getFunction(_names[i]);
}

Real
DwarfElephantPicewiseFunction::value(Real t, const Point & p) const
{
  // return _funcs[0]->value(t,p)*_funcs[1]->value(0,p);
  Real value = 0;
  if(t<=(2.54406006-_thresholds[0]))
    value = _funcs[0]->value(t,p); //+_funcs[0]->value(t,p);
  else if(t>(2.54406006-_thresholds[0]) && t<=(2.54406006-_thresholds[1]))
    value = _funcs[1]->value(t,p); //+_funcs[0]->value(t,p);
  else if(t>(2.54406006-_thresholds[1]) && t<(2.54406006-_thresholds[2]))
    value = _funcs[2]->value(t,p); //+_funcs[0]->value(t,p);
  else
    value = _funcs[3]->value(t,p); //+_funcs[0]->value(t,p);

  return value * _funcs[4]->value(0,p);

}
