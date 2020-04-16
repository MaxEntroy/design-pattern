local ComputingFactory = require "computing_factory"
local SimpleComputingFactory = require "simple_computing_factory"

local AddComputing = require "add_computing"
local MinusComputing = require "minus_computing"

local function test_factory()
  local AddComputingFactory = ComputingFactory.New(AddComputing.name)
  local add_obj = AddComputingFactory:GetComputing(3, 4)
  print(add_obj:DoComputing())

  local MinusComputingFactory = ComputingFactory.New(MinusComputing.name)
  local add_obj = MinusComputingFactory:GetComputing(3, 4)
  print(add_obj:DoComputing())
end

local function test_simple_factory()
  local add_obj = SimpleComputingFactory.GetComputing(AddComputing.name, 3, 4)
  print(add_obj:DoComputing())

  local minus_obj = SimpleComputingFactory.GetComputing(MinusComputing.name, 3, 4)
  print(minus_obj:DoComputing())
end

test_factory()

test_simple_factory()
