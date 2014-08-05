<% render(instance) %>
<%= includes((1..x+1).size) %>

#include <boost/hana/list/list.hpp>


template <typename ...>
struct result { };

struct f {
    template <typename State, typename X>
    constexpr result<State, X> operator()(State, X) const { return {}; }
};

template <int> struct x { };

int main() {
    auto go = boost::hana::scanl1(
        <%= list(
            (1..x+1).map { |i| "x<#{i}>" },
            (1..x+1).map { |i| "x<#{i}>{}" }
        ) %>,
        f{}
    );
}
