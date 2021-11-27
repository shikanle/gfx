#pragma once

template <typename float_system>
class expression {
public:
    typedef float_system float_system_t;
    typedef typename float_system_t::float_t float_t;

    struct node {
        enum class kind_type {
            variable_t = 0,
            variable_u,
            variable_v,
            immediate,
            add, subtract, multiply, divide, modulo,
            negate, power,
            sqrt, exp, log,
            sin, cos, tan,
            asin, acos, atan,
            sinh, cosh, tanh,
            asinh, acosh, atanh,
            round, ceil, floor
        } kind;

        float_t value;
        
        reflectible(node, {
            register_enum(kind);
            register_field(value);
        });
    };

public:
    std::vector<node> nodes;

    reflectible(expression, {
        register_field(nodes);
    });

public:
    inline expression() : nodes() {}
    inline expression(float_t v) : nodes() {
        this->nodes.push_back({ node::kind_type::immediate, v });
    }
    inline expression(typename node::kind_type t, float_t v = float_system_t::zero()) : nodes() {
        this->nodes.push_back({ t, v });
    }

protected:
    float_t evaluate(const float *vars, int &i) const {
        #define v this->evaluate(vars, i)
        auto &o = this->nodes[i--];
        float_t retval;
        switch (o.kind) {
            case node::kind_type::immediate: return o.value;
            case node::kind_type::variable_t: retval = vars[0]; break;
            case node::kind_type::variable_u: retval = vars[1]; break;
            case node::kind_type::variable_v: retval = vars[2]; break;
            case node::kind_type::add: retval = v + v; break;
            case node::kind_type::subtract: retval = v - v; break;
            case node::kind_type::multiply: retval = v * v; break;
            case node::kind_type::divide: retval = v / v; break;
            case node::kind_type::modulo: retval = float_system_t::fmod(v, v); break;
            case node::kind_type::negate: retval = -v; break;
            case node::kind_type::power: retval = float_system_t::power(v, v); break;
            case node::kind_type::sqrt: retval = float_system_t::sqrt(v); break;
            case node::kind_type::exp: retval = float_system_t::exp(v); break;
            case node::kind_type::log: retval = float_system_t::log(v); break;
            case node::kind_type::sin: retval = float_system_t::sin(v); break;
            case node::kind_type::cos: retval = float_system_t::cos(v); break;
            case node::kind_type::tan: retval = float_system_t::tan(v); break;
            case node::kind_type::asin: retval = float_system_t::asin(v); break;
            case node::kind_type::acos: retval = float_system_t::acos(v); break;
            case node::kind_type::atan: retval = float_system_t::atan(v); break;
            case node::kind_type::sinh: retval = float_system_t::sinh(v); break;
            case node::kind_type::cosh: retval = float_system_t::cosh(v); break;
            case node::kind_type::tanh: retval = float_system_t::tanh(v); break;
            case node::kind_type::asinh: retval = float_system_t::asinh(v); break;
            case node::kind_type::acosh: retval = float_system_t::acosh(v); break;
            case node::kind_type::atanh: retval = float_system_t::atanh(v); break;
            case node::kind_type::round: retval = float_system_t::round(v); break;
            case node::kind_type::ceil: retval = float_system_t::ceil(v); break;
            case node::kind_type::floor: retval = float_system_t::floor(v); break;
            default: return float_system_t::zero();
        }
        #undef v
        if (o.value != 0) {
            return o.value * retval;
        }
        return retval;
    }

public:
    float_t operator()(const float *vars) const {
        if (this->nodes.size() == 0) {
            return float_system_t::zero();
        }
        int i = (int)this->nodes.size() - 1;
        return this->evaluate(vars, i);
    }

    #define declare_expression_binary_op(op, opname) \
    expression op(const expression &v) const { \
        expression retval; \
        for (auto &el : v.nodes) { \
            retval.nodes.push_back(el); \
        } \
        for (auto &el : this->nodes) { \
            retval.nodes.push_back(el); \
        } \
        retval.nodes.push_back({ node::kind_type::opname, 0 }); \
        return retval; \
    }
    declare_expression_binary_op(operator+, add)
    declare_expression_binary_op(operator-, subtract)
    declare_expression_binary_op(operator*, multiply)
    declare_expression_binary_op(operator/, divide)
    declare_expression_binary_op(operator%, modulo)
    declare_expression_binary_op(fmod, modulo)
    declare_expression_binary_op(power, power)
    #undef declare_expression_binary_op

    #define declare_expression_unitary_op(opname) \
    expression opname() const { \
        expression retval; \
        for (auto &el : this->nodes) { \
            retval.nodes.push_back(el); \
        } \
        retval.nodes.push_back({ node::kind_type::opname, 0 }); \
        return retval; \
    }
    declare_expression_unitary_op(sqrt)
    declare_expression_unitary_op(exp)
    declare_expression_unitary_op(log)
    declare_expression_unitary_op(sin)
    declare_expression_unitary_op(cos)
    declare_expression_unitary_op(tan)
    declare_expression_unitary_op(sinh)
    declare_expression_unitary_op(cosh)
    declare_expression_unitary_op(tanh)
    declare_expression_unitary_op(asin)
    declare_expression_unitary_op(acos)
    declare_expression_unitary_op(atan)
    declare_expression_unitary_op(asinh)
    declare_expression_unitary_op(acosh)
    declare_expression_unitary_op(atanh)
    declare_expression_unitary_op(floor)
    declare_expression_unitary_op(ceil)
    declare_expression_unitary_op(round)
    #undef declare_expression_unitary_op
};