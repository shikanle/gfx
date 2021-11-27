#pragma once

template <typename float_system>
class equation {
public:
    typedef float_system float_system_t;
    typedef typename float_system::float_t float_t;

    struct root {
        float_t value;
        int multiplicity;

        reflectible(root, {
            register_field(value);
            register_field(multiplicity);
        });

        inline root() {}
        inline root(float_t value) : value(value), multiplicity(1) {}
        inline root(float_t value, int multiplicity) : value(value), multiplicity(multiplicity) {}
    };

    template <int max_roots>
    struct solution {
        int count;
        root roots[max_roots];

        inline solution() : count(0) {}

        template <int max_roots_2>
        inline solution(const solution<max_roots_2> &v) : count(v.count) {
            for (int i = 0; i < v.count; i++) {
                this->roots[i] = v.roots[i];
            }
        }

        inline bool infinite() const { 
            return count < 0;
        }

        const gfx::reflection &type() const {
            return *gfx::reflection::retrieve("solution", &(typeid(solution)), [this](gfx::reflection &__reflection_obj) {});
        }

        std::string json(int indent = 0, bool has_type = false) const {
            if (this->infinite()) {
                return "undefined";
            }
            std::stringstream ss;
            ss << "[";
            for (int i = 0; i < this->count; i++) {
                ss << this->roots[i].json();
                if (i + 1 < this->count) {
                    if (indent > 0) {
                        ss << ", ";
                    } else {
                        ss << ",";
                    }
                }
            }
            ss << "]";
            return ss.str();
        }

        friend std::ostream &operator<<(std::ostream &o, const solution &v) {
            o << v.type().name << " " << v.json(); \
            return o;
        }
    };

public:
    reflectible(equation, {
    });
};