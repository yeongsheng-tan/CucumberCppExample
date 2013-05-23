require 'fixture_glue'

Given /^the input "([^"]*)"$/ do |arg1|
    @calc = RpnCalcFixture.new
    arg1.split(/ /).collect{ |s| @calc.enter(s.to_i)}
end

When /^the calculator performs "([^"]*)"$/ do |arg1|
    @calc.perform(arg1)
end

Then /^the result should be "([^"]*)"$/ do |arg1|
    # this should call getX, but the real calc is not implemented
end