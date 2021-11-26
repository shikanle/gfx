#pragma once

template <typename float_system, int row, int column>
class matrix {
private:
    typedef Eigen::Matrix<typename float_system::float_t, row, column> eigen_t;

public:
    eigen_t data;

public:
    inline matrix() : data() {}

    const gfx::reflection &type() const {
        return *gfx::reflection::retrieve("matrix", &(typeid(matrix)), [this](gfx::reflection &__reflection_obj) {});
    }

    std::string json(int indent = 0, bool has_type = false) const {
        std::stringstream ss;
        ss << "[";
        if (indent > 0) {
            ss << std::endl;
        }
        for (int i = 0; i < this->data.rows(); i++) {
            if (indent > 0) {
                ss << std::string(indent, ' ');
            }
            ss << "[";
            for (int j = 0; j < this->data.cols(); j++) {
                ss << data(i, j);
                if (j + 1 != this->data.cols()) {
                    if (indent > 0) {
                        ss << ", ";
                    } else {
                        ss << ",";
                    }
                }
            }
            if (i + 1 != this->data.rows()) {
                ss << "],";
            } else {
                ss << "]";
            }
            if (indent > 0) {
                ss << std::endl;
            }
        }
        ss << "]";
        return ss.str();
    }

    friend std::ostream &operator<<(std::ostream &o, const matrix &v) {
        o << v.type().name << " " << v.json(); \
        return o;
    }
};

