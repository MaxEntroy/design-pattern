local _M = {}

_M.name = "minus_computing"

function _M.New(l, r)
  local o = {
    left = l,
    right =r
  }
  setmetatable(o, {__index = _M})

  return o
end

function _M.DoComputing(self)
  return self.left - self.right
end

return _M
