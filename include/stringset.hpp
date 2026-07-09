#pragma once

namespace containers {
class StringSet {
public:
    StringSet();
    StringSet(const StringSet&);
    StringSet(StringSet&&);
    StringSet& operator=(const StringSet&);
    StringSet& operator=(StringSet&&);
    ~StringSet();

private:

};
} // namespace containers
