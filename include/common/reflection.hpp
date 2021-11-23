#pragma once

class reflection {
public:
    class reflection_library : public std::unordered_map<const std::type_info *, reflection *> {
    public:
        reflection_library() {
            #define declare_primitive_type(c, el) \
                (*this)[&typeid(c)] = new reflection(#c, &typeid(c), type_kind::el);
            declare_primitive_type(int8_t, int8_type);
            declare_primitive_type(int16_t, int16_type);
            declare_primitive_type(int32_t, int32_type);
            declare_primitive_type(int64_t, int64_type);
            declare_primitive_type(uint8_t, uint8_type);
            declare_primitive_type(uint16_t, uint16_type);
            declare_primitive_type(uint32_t, uint32_type);
            declare_primitive_type(uint64_t, uint64_type);
            declare_primitive_type(bool, bool_type);
            declare_primitive_type(float, float32_type);
            declare_primitive_type(double, float64_type);
            declare_primitive_type(std::string, string_type);
            #undef declare_primitive_type
        }
    };

    struct field {
        std::string name;
        size_t offset;
        const std::type_info *type_info;

        const reflection &type() const {
            return *reflection::retrieve(type_info);
        }
        friend std::ostream &operator<<(std::ostream &o, const field &v) {
            o << v.name << ": " << v.type();
            return o;
        }
    };

    enum class type_kind {
        unknown,
        int8_type,
        int16_type,
        int32_type,
        int64_type,
        uint8_type,
        uint16_type,
        uint32_type,
        uint64_type,
        bool_type,
        float32_type,
        float64_type,
        string_type,
        class_type,
        array_type,
        enum_type
    };

    struct primitive_types {
        std::unordered_map<const std::type_info *, type_kind> types;
        primitive_types() : types() {
            this->types[&typeid(int8_t)] = type_kind::int8_type;
            this->types[&typeid(int16_t)] = type_kind::int16_type;
            this->types[&typeid(int32_t)] = type_kind::int32_type;
            this->types[&typeid(int64_t)] = type_kind::int64_type;
            this->types[&typeid(uint8_t)] = type_kind::uint8_type;
            this->types[&typeid(uint16_t)] = type_kind::uint16_type;
            this->types[&typeid(uint32_t)] = type_kind::uint32_type;
            this->types[&typeid(uint64_t)] = type_kind::uint64_type;
            this->types[&typeid(bool)] = type_kind::bool_type;
            this->types[&typeid(float)] = type_kind::float32_type;
            this->types[&typeid(double)] = type_kind::float64_type;
            this->types[&typeid(std::string)] = type_kind::string_type;
        }

        static type_kind find(const std::type_info *v) {
            static primitive_types primitives;
            auto el = primitives.types.find(v);
            if (el == primitives.types.end()) {
                return type_kind::unknown;
            }
            return el->second;
        }
    };

public:
    std::string name;
    const std::type_info *type_info;
    std::vector<field> fields;
    std::vector<field> supers;
    type_kind kind;

public:
    reflection() : type_info(nullptr), fields(), supers(), kind(type_kind::unknown) {}
    reflection(const std::string &name, const std::type_info *info, type_kind kind = type_kind::unknown) 
        : name(name), type_info(info), fields(), supers(), kind(kind) {
        if (this->kind == type_kind::unknown) {
            this->kind = primitive_types::find(info);
            if (this->kind == type_kind::unknown) {
                this->kind = type_kind::class_type;
            }
        }
    }

public:
    std::string to_string() const {
        switch (this->kind) {
            case type_kind::unknown: return "<unknown>";
            case type_kind::int8_type: return "int8";
            case type_kind::int16_type: return "int16";
            case type_kind::int32_type: return "int32";
            case type_kind::int64_type: return "int64";
            case type_kind::uint8_type: return "uint8";
            case type_kind::uint16_type: return "uint16";
            case type_kind::uint32_type: return "uint32";
            case type_kind::uint64_type: return "uint64";
            case type_kind::bool_type: return "bool";
            case type_kind::float32_type: return "float32";
            case type_kind::float64_type: return "float64";
            case type_kind::string_type: return "string";
            case type_kind::enum_type: return "enum";
            case type_kind::class_type: return "class " + this->name;
            case type_kind::array_type: return "vector<" + 
                retrieve(this->fields[0].type_info)->to_string() + ">";
            default: return "<not implemented>";
        }
    }

    std::vector<field> all_fields() const {
        std::vector<field> retval;
        for (auto &el : this->supers) {
            for (auto &f : el.type().all_fields()) {
                field newf = f;
                newf.offset += el.offset;
                retval.push_back(newf);
            }
        }
        for (auto &el : this->fields) {
            retval.push_back(el);
        }
        return retval;
    } 

    std::string to_json(const void *p, bool has_type = false, int indent = 4, int prefix = 0) const {
        switch (this->kind) {
            case type_kind::unknown: return "undefined";
            case type_kind::int8_type: return std::to_string((int64_t)(*((const int8_t *)p)));
            case type_kind::int16_type: return std::to_string((int64_t)(*((const int16_t *)p)));
            case type_kind::int32_type: return std::to_string((int64_t)(*((const int32_t *)p)));
            case type_kind::int64_type: return std::to_string((int64_t)(*((const int64_t *)p)));
            case type_kind::uint8_type: return std::to_string((uint64_t)(*((const uint8_t *)p)));
            case type_kind::uint16_type: return std::to_string((uint64_t)(*((const uint16_t *)p)));
            case type_kind::uint32_type: return std::to_string((uint64_t)(*((const uint32_t *)p)));
            case type_kind::uint64_type: return std::to_string((uint64_t)(*((const uint64_t *)p)));
            case type_kind::bool_type: return *((const bool *)p) ? "true" : "false";
            case type_kind::float32_type: return std::to_string(*(const float *)p);
            case type_kind::float64_type: return std::to_string(*(const double *)p);
            case type_kind::string_type: return "\"" + *(const std::string *)p + "\"";
            case type_kind::enum_type: {
                switch (this->fields[0].offset) {
                    case 1: return std::to_string((int64_t)(*((const int8_t *)p)));
                    case 2: return std::to_string((int64_t)(*((const int16_t *)p)));
                    case 4: return std::to_string((int64_t)(*((const int32_t *)p)));
                    case 8: return std::to_string((int64_t)(*((const int64_t *)p)));
                    default: return "enum";
                }
            }
            case type_kind::array_type: {
                std::stringstream ss;
                std::string pref;
                if (indent > 0) {
                    pref = std::string(prefix + indent, ' ');
                }
                ss << "[";
                if (indent > 0) {
                    ss << std::endl;
                }
                auto arr = ((std::vector<char> *)p);
                auto dataptr = arr->data();
                auto &subtype = this->fields[0].type();
                auto elsize = this->fields[0].offset;
                auto allsize = arr->size() / elsize;
                for (int i = 0; i < allsize; i++) {
                    ss << pref;
                    ss << subtype.to_json(dataptr, has_type, indent, prefix + indent);
                    dataptr += elsize;
                    if (i + 1 != allsize) {
                        ss << ",";
                    }
                    if (indent > 0) {
                        ss << std::endl;
                    }
                }
                if (indent > 0) {
                    ss << std::string(prefix, ' ');
                }
                ss << "]";
                return ss.str();
            }
            case type_kind::class_type: {
                std::stringstream ss;
                std::string pref;
                if (indent > 0) {
                    pref = std::string(prefix + indent, ' ');
                }
                ss << "{";
                if (indent > 0) {
                    ss << std::endl;
                }
                if (has_type) {
                    ss << pref << "\"@type\":";
                    if (indent > 0) {
                        ss << " ";
                    }
                    ss << "\"" << this->name << "\",";
                    if (indent > 0) {
                        ss << std::endl;
                    }
                }
                auto all_fds = this->all_fields();
                for (size_t i = 0; i < all_fds.size(); i++) {
                    const auto &el = all_fds[i];
                    ss << pref << "\"" << el.name << "\":";
                    if (indent > 0) {
                        ss << " ";
                    }
                    ss << el.type().to_json((const char *)p + el.offset, has_type, indent, prefix + indent);
                    if (i + 1 != all_fds.size()) {
                        ss << ",";
                    }
                    if (indent > 0) {
                        ss << std::endl;
                    }
                }
                if (indent > 0) {
                    ss << std::string(prefix, ' ');
                }
                ss << "}";
                return ss.str();
            }
            default:
                return "undefined";
        }
    }

    std::string to_code(int indent = 0) const {
        std::stringstream ss;
        ss << this->to_string();
        if (this->kind == type_kind::class_type) {
            ss << " {" << std::endl;
            for (auto &el : this->all_fields()) {
                for (int i = 0; i < indent + 4; i++) {
                    ss << " ";
                }
                ss << el.name << ": " << el.type().to_code(indent + 4) << "," << std::endl;
            }
            for (int i = 0; i < indent; i++) {
                ss << " ";
            }
            ss << "}";
        }
        return ss.str();
    }

    friend std::ostream &operator<<(std::ostream &o, const reflection &v) {
        o << v.to_string();
        return o;
    }

    static inline reflection *retrieve(const std::type_info *info) {
        std::mutex &m = global_lock();
        m.lock();
        reflection_library &lib = library();
        auto el = lib.find(info);
        if (el == lib.end()) {
            m.unlock();
            static reflection unknown_type;
            return &unknown_type;
        }
        m.unlock();
        return el->second;
    }

    static inline reflection *retrieve(const std::string &name, const std::type_info *info, std::function<void (reflection &)> f) {
        std::mutex &m = global_lock();
        m.lock();
        reflection_library &lib = library();
        auto el = lib.find(info);
        if (el == lib.end()) {
            auto ref = new reflection(name, info);
            lib[info] = ref;
            m.unlock();
            f(*ref);
            return ref;
        } else {
            m.unlock();
            return el->second;
        }
    }

protected:
    inline static reflection_library &library() {
        static reflection_library lib;
        return lib;
    }

    inline static std::mutex &global_lock() {
        static std::mutex m;
        return m;
    }

public:
    template <typename T>
    static const std::type_info *array_element_type(const std::vector<T> &) {
        return &typeid(T);
    }

    template <typename T>
    static const std::type_info *array_element_type(const T &) {
        return nullptr;
    }

    static void expand_field(const int8_t &) {}
    static void expand_field(const int16_t &) {}
    static void expand_field(const int32_t &) {}
    static void expand_field(const int64_t &) {}
    static void expand_field(const uint8_t &) {}
    static void expand_field(const uint16_t &) {}
    static void expand_field(const uint32_t &) {}
    static void expand_field(const uint64_t &) {}
    static void expand_field(const bool &) {}
    static void expand_field(const float &) {}
    static void expand_field(const double &) {}
    static void expand_field(const std::string &) {}
    template <typename T>
    static void expand_field(const std::vector<T> &v) {
        T val;
        auto &t = val.type();
        retrieve("vector<" + t.name + ">", &typeid(std::vector<T>), [](reflection &f) {
            f.kind = type_kind::array_type;
            f.fields.push_back({"", sizeof(T), &typeid(T)});
        });
    }
    template <typename T>
    static void expand_field(const T &v) {
        v.type();
    }
};

#define register_enum(v) { \
        gfx::reflection::field __f = {#v, (size_t)((char *)&(this->v) - (char *)this), &typeid(this->v)}; \
        gfx::reflection::retrieve(#v, &typeid(this->v), [this](reflection &f) { \
            f.kind = gfx::reflection::type_kind::enum_type; \
            f.fields.push_back({"", sizeof(this->v), &typeid(this->v)}); \
        }); \
        __reflection_obj.fields.push_back(__f); \
    }

#define register_field(v) { \
        gfx::reflection::field __f = {#v, (size_t)((char *)&(this->v) - (char *)this), &typeid(this->v)}; \
        gfx::reflection::expand_field(this->v); \
        __reflection_obj.fields.push_back(__f); \
    }

#define register_super(t) {\
        gfx::reflection::field __f = {#t, (size_t)((char *)((const t *)this) - (char *)this), &typeid(t)}; \
        this->t::type(); \
        __reflection_obj.supers.push_back(__f); \
    }

#define reflectible(class_name, code) \
    const gfx::reflection &type() const { \
        return *gfx::reflection::retrieve(#class_name, &(typeid(class_name)), [this](gfx::reflection &__reflection_obj) code); \
    } \
    std::string json(int indent = 0, bool has_type = false) const { \
        return this->type().to_json(this, has_type, indent, 0); \
    } \
    friend std::ostream &operator<<(std::ostream &o, const class_name &v) { \
        o << v.type().name << " " << v.json(); \
        return o; \
    }

#define dynamic_reflectible(class_name, code) \
    virtual const gfx::reflection &type() const override { \
        return *gfx::reflection::retrieve(#class_name, &(typeid(class_name)), [this](gfx::reflection &__reflection_obj) code); \
    } \
    virtual std::string json(int indent = 0, bool has_type = false) const override { \
        return this->type().to_json(this, has_type, indent, 0); \
    } \
    friend std::ostream &operator<<(std::ostream &o, const class_name &v) { \
        o << v.type().name << " " << v.json(); \
        return o; \
    }
    
class object {
public:
    virtual const reflection &type() const {
        return *reflection::retrieve("object", &(typeid(object)), [this](reflection &__reflection_obj) {});
    }

    virtual std::string json(int indent = 0, bool has_type = false) const {
        return this->type().to_json(this, has_type, indent, 0);
    }
};
