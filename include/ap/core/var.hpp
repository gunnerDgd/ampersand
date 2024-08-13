#ifndef AP_VAR_HPP
#define AP_VAR_HPP

#include <ap/core/operator.hpp>
#include <ap/core/float.hpp>
#include <ap/core/int.hpp>
#include <ap/core/pack.hpp>

#include <ap/meta/src.hpp>
#include <ap/meta/meta.hpp>
#include <ap/trait.hpp>

#include <string_view>
#include <list>

namespace ap                          {
    template <typename... T> class var;

    template <is::bool_t T>
    class var<T> 
        : public boolean <var<T>>,
          public move    <var<T>>                                  {
        using str_t = std::string_view;
        
        template <is::bool_t V> friend auto type(const ap::var<V>&);
        template <is::bool_t V> friend auto name(const ap::var<V>&);
        str_t name;

    public:
        var(T, str_t name)
            : boolean <var<T>> (*this),
              move    <var<T>> (*this),
              name (name)
                {}
    };

    template <is::int_t T>
    class var<T> 
        : public ari_eq <var<T>>,
          public ari    <var<T>>,
    
          public bit_eq <var<T>>,
          public bit    <var<T>>,
    
          public move   <var<T>>,
          
          public boolean<var<T>>,
          public cmp    <var<T>>,
          public ord    <var<T>>
                                                                  {
        using str_t = std::string_view;

        template <is::num_t V> friend auto type(const ap::var<V>&);
        template <is::num_t V> friend auto name(const ap::var<V>&);
        str_t name;
    public:
        var(T, str_t name)
            : ari_eq <var <T>> (*this),
              bit_eq <var <T>> (*this),
              
              ari    <var <T>> (*this),
              bit    <var <T>> (*this),

              move   <var <T>> (*this),
              
              boolean<var <T>> (*this),
              cmp    <var <T>> (*this),
              ord    <var <T>> (*this),

              name             (name)
                {}

        auto 
            operator=(auto arg)                                    {
                auto&  self = static_cast<ap::move<var<T>>&>(*this);
                return self = arg;
        }
    };

    template <is::float_t T>
    class var<T> 
        : public ari_eq <var<T>>,
          public ari    <var<T>>,
                    
          public move   <var<T>>,

          public boolean<var<T>>,
          public cmp    <var<T>>,
          public ord    <var<T>>

                                                                  {
        template <is::num_t V> friend auto type(const ap::var<V>&);
        template <is::num_t V> friend auto name(const ap::var<V>&);

        using str_t = std::string_view;
        str_t name;
    public:
        var(T, str_t name)
            : ari_eq <var <T>> (*this),
              ari    <var <T>> (*this),

              move   <var <T>> (*this),

              boolean<var <T>> (*this),
              cmp    <var <T>> (*this),
              ord    <var <T>> (*this),

              name             (name)
                {}

        auto 
            operator=(auto arg)                                    {
                auto&  self = static_cast<ap::move<var<T>>&>(*this);
                return self = arg;
        }
    };     

    template <is::pack_t T>
    class var<T> 
        : public move <var<T>> 
                                                                                  {    
        template <std::size_t I, is::pack_t V> friend auto sub (const ap::var<V>&);
        template <is::pack_t V>                friend auto type(const ap::var<V>&);
        template <is::pack_t V>                friend auto name(const ap::var<V>&);

        using str_t = std::string_view;
        str_t name;
        T     pack;
    public:
        auto 
            operator=(var<T>& arg)                                 {
                auto&  self = static_cast<ap::move<var<T>>&>(*this);
                auto&  move = static_cast<ap::move<var<T>>&>(arg);
                return self = move;
        }

    public:
        var(T pack, str_t name)
            : move <var<T>> (*this),
              name (name),
              pack (pack)
                {}
    };

    template <is::pack_t P, typename T> var(var<P>, var<T>) -> var <var<P>, var<T>>;

    template <is::pack_t T> var(T, std::string_view) -> var<T>;
    template <is::num_t  T> var(T, std::string_view) -> var<T>;
}


namespace ap                                                                    {
    // For var<is::pack_T T>
    template <is::pack_t T> auto type(const ap::var<T>& var) { return var.pack; }
    template <is::pack_t T> auto name(const ap::var<T>& var) { return var.name; }

    template <is::pack_t V, std::size_t I>
    auto 
        sub (const ap::var<V>& var) {
            auto pack = var .pack;
            auto type = pack.type;

            return ap::var { var, std::get<I>(type) };
    }

    // For var<is::var_t T, is::var_t U>
    template <is::pack_t P, typename T>
    auto 
        self(const ap::var<ap::var<P>, ap::var<T>>& var) {
            return var.self;
    }

    // For var<is::bool_t T>, var <is::int_t T> and var <is::float_t T>
    template <is::bool_t T> auto type(const ap::var<T>& var) { return T(); }
    template <is::num_t T>  auto type(const ap::var<T>& var) { return T(); }

    template <is::bool_t T> auto name(const ap::var<T>& var) { return var.name; }
    template <is::num_t T>  auto name(const ap::var<T>& var) { return var.name; }
}




// For Pack Referenced Variables
namespace ap                                   {
    template <typename... P, is::bool_t T>
    class var <var<P...>, var<T>> 
        : public boolean <var<var<P...>, var<T>>>,
          public move    <var<var<P...>, var<T>>>
                                                                                                              {
        template <typename... T1, typename   T2> friend auto self(const ap::var<ap::var<T1...>, ap::var<T2>>&);
        template <typename... T1, is::bool_t T2> friend auto type(const ap::var<ap::var<T1...>, ap::var<T2>>&);
        template <typename... T1, is::bool_t T2> friend auto name(const ap::var<ap::var<T1...>, ap::var<T2>>&);

        friend class var<P>;
        var<P...> self;
        var<T>    sub;

        var(var<P...> sup, var<T> sub)
            : boolean <ap::var<ap::var<P...>, ap::var<T>>>(*this),
              move    <ap::var<ap::var<P...>, ap::var<T>>>(*this),

              self (sup),
              sub  (sub)
                {}
    };

    template <typename... P, is::int_t T>
    class var<var<P...>, var<T>>
        : public ari_eq <var<var<P...>, var<T>>>,
          public ari    <var<var<P...>, var<T>>>,
    
          public bit_eq <var<var<P...>, var<T>>>,
          public bit    <var<var<P...>, var<T>>>,
    
          public move   <var<var<P...>, var<T>>>,
          
          public boolean<var<var<P...>, var<T>>>,
          public cmp    <var<var<P...>, var<T>>>,
          public ord    <var<var<P...>, var<T>>>
                                                                                                             {
        template <typename... T1, typename  T2> friend auto self(const ap::var<ap::var<T1...>, ap::var<T2>>&);
        template <typename... T1, is::num_t T2> friend auto type(const ap::var<ap::var<T1...>, ap::var<T2>>&);
        template <typename... T1, is::num_t T2> friend auto name(const ap::var<ap::var<T1...>, ap::var<T2>>&);

        friend class var<P...>;
        var<P...> self;
        var<T>    sub;
        
    public:
        var(var<P...> sup, var<T> sub)
            : ari_eq <ap::var <ap::var<P...>, ap::var<T>>> (*this),
              bit_eq <ap::var <ap::var<P...>, ap::var<T>>> (*this),
              
              ari    <ap::var <ap::var<P...>, ap::var<T>>> (*this),
              bit    <ap::var <ap::var<P...>, ap::var<T>>> (*this),

              move   <ap::var <ap::var<P...>, ap::var<T>>> (*this),
              
              boolean<ap::var <ap::var<P...>, ap::var<T>>> (*this),
              cmp    <ap::var <ap::var<P...>, ap::var<T>>> (*this),
              ord    <ap::var <ap::var<P...>, ap::var<T>>> (*this),

              self (sup),
              sub  (sub)
                {}

        auto 
            operator=(auto arg)                                                    {
                auto&  self = static_cast<ap::move<var<var<P...>, var<T>>>&>(*this);
                return self = arg;
        }
    };

    template <typename... P, is::float_t T>
    class var<var<P...>, var<T>>
        : public ari_eq <var<var<P...>, var<T>>>,
          public ari    <var<var<P...>, var<T>>>,
                    
          public move   <var<var<P...>, var<T>>>,

          public boolean<var<var<P...>, var<T>>>,
          public cmp    <var<var<P...>, var<T>>>,
          public ord    <var<var<P...>, var<T>>>

                                                                                                             {
        template <typename... T1, typename  T2> friend auto self(const ap::var<ap::var<T1...>, ap::var<T2>>&);
        template <typename... T1, is::num_t T2> friend auto type(const ap::var<ap::var<T1...>, ap::var<T2>>&);
        template <typename... T1, is::num_t T2> friend auto name(const ap::var<ap::var<T1...>, ap::var<T2>>&);

        friend class var<P...>;
        var<P...> self;
        var<T>    sub;

    public:
        var(var<P...> sup, var<T> sub)
            : ari_eq <ap::var <ap::var<P...>, ap::var<T>>> (*this),
              ari    <ap::var <ap::var<P...>, ap::var<T>>> (*this),

              move   <ap::var <ap::var<P...>, ap::var<T>>> (*this),

              boolean<ap::var <ap::var<P...>, ap::var<T>>> (*this),
              cmp    <ap::var <ap::var<P...>, ap::var<T>>> (*this),
              ord    <ap::var <ap::var<P...>, ap::var<T>>> (*this),

              self (sup),
              sub  (sub)
                {}

        auto 
            operator=(auto arg)                                                                {
                auto&  self = static_cast<ap::move<ap::var<ap::var<P...>, ap::var<T>>>&>(*this);
                return self = arg;
        }
    };     

    template <typename... P, is::pack_t T>
    class var<var<P...>, var<T>>
        : public move <var<var<P...>, var<T>>>                                        
                                                                                                                             {
        template <typename... T1, typename   T2>                friend auto self(const ap::var<ap::var<T1...>, ap::var<T2>>&);
        template <typename... T1, is::pack_t T2>                friend auto type(const ap::var<ap::var<T1...>, ap::var<T2>>&);
        template <typename... T1, is::pack_t T2>                friend auto name(const ap::var<ap::var<T1...>, ap::var<T2>>&);
        template <typename... T1, is::pack_t T2, std::size_t I> friend auto sub (const ap::var<ap::var<T1...>, ap::var<T2>>&);
        var<P...> self;
        var<T>    sub;
        
    public:
        auto 
            operator=(var<var<P...>, var<T>>& arg)                                 {
                auto&  self = static_cast<ap::move<var<var<P...>, var<T>>>&>(*this);
                auto&  move = static_cast<ap::move<var<var<P...>, var<T>>>&>(arg);
                return self = move;
        }

    public:
        var(var<P...> sup, var<T> sub)
            : move <ap::var<ap::var<P...>, ap::var<T>>> (*this),

              self(sup),
              sub (sub)
                {}
    };

    template <typename... P, is::bool_t T>  var(ap::var<P...>, var<T>) -> var <var<P...>, var<T>>;
    template <typename... P, is::int_t T>   var(ap::var<P...>, var<T>) -> var <var<P...>, var<T>>;
    template <typename... P, is::float_t T> var(ap::var<P...>, var<T>) -> var <var<P...>, var<T>>;
    template <typename... P, is::pack_t T>  var(ap::var<P...>, var<T>) -> var <var<P...>, var<T>>;
}



namespace ap                                                                                                                           {
    // For var<is::pack_T T>
    template <typename... P, is::pack_t T>                auto type(const ap::var<var<P...>, var<T>>& var) { return ap::type(var.sub); }
    template <typename... P, is::pack_t T>                auto name(const ap::var<var<P...>, var<T>>& var) { return ap::name(var.sub); }
    template <std::size_t I, typename... P, is::pack_t T> auto sub (const ap::var<var<P...>, var<T>>& var) { return ap::sub (var.sub); }

    // For var<is::var_t T, is::var_t U>
    template <typename... P, typename T> auto self(const ap::var<ap::var<P...>, ap::var<T>>& var) { return var.self; }

    // For var<is::bool_t T>, var <is::int_t T> and var <is::float_t T>

    template <typename... P, is::bool_t T> auto name(const ap::var<var<P...>, var<T>>& var) { return ap::name (var.sub); }
    template <typename... P, is::num_t T>  auto name(const ap::var<var<P...>, var<T>>& var) { return ap::name (var.sub); }
    template <typename... P, is::bool_t T> auto type(const ap::var<var<P...>, var<T>>& var) { return T(); }
    template <typename... P, is::num_t T>  auto type(const ap::var<var<P...>, var<T>>& var) { return T(); }
}


// For Array Type Support
namespace ap                                                          {
    template <is::num_t T>
    class var<T[]> 
        : public move <var<T[]>>,
          public idx  <var<T[]>>
                                                                      {
        using str_t = std::string_view;
        using len_t = std::uint64_t;

        template <is::num_t T1> friend auto type(const ap::var<T1[]>&);
        template <is::num_t T1> friend auto name(const ap::var<T1[]>&);
        template <is::num_t T1> friend auto len (const ap::var<T1[]>&);
        str_t name;
        len_t len;
    public:
        auto 
            operator=(var<T[]>& arg)                                 {
                auto&  self = static_cast<ap::move<var<T[]>>&>(*this);
                auto&  move = static_cast<ap::move<var<T[]>>&>(arg);
                return self = move;
        }

    public:
        var(T, str_t name, len_t len)
            : move <var<T[]>>(*this),
              idx  <var<T[]>>(*this),

              name (name),
              len  (len)
                {}
    };

    template <is::pack_t T>
    class var<T[]> 
        : public move <var<T[]>>,
          public idx  <var<T[]>>
                                                                       {
        using str_t = std::string_view;
        using len_t = std::uint64_t;
        T pack;

        template <is::pack_t T1> friend auto type(const ap::var<T1[]>&);
        template <is::pack_t T1> friend auto name(const ap::var<T1[]>&);
        template <is::pack_t T1> friend auto len (const ap::var<T1[]>&);
        str_t name;
        len_t len;
    public:
        auto 
            operator=(var<T[]>& arg)                                 {
                auto&  self = static_cast<ap::move<var<T[]>>&>(*this);
                auto&  move = static_cast<ap::move<var<T[]>>&>(arg);
                return self = move;
        }

    public:
        var(T pack, str_t name, len_t len)
            : move <var<T[]>>(*this),
              idx  <var<T[]>>(*this),
                
              pack (pack),
              name (name),
              len  (len)
                {}
    };

    template <is::pack_t T> var (T, std::string_view, std::uint64_t) -> var <T[]>;
    template <is::num_t  T> var (T, std::string_view, std::uint64_t) -> var <T[]>;
}

namespace ap                                                                        {
    template <is::pack_t T1> auto type(const ap::var<T1[]>& var) { return var.pack; }
    template <is::pack_t T1> auto name(const ap::var<T1[]>& var) { return var.name; }
    template <is::pack_t T1> auto len (const ap::var<T1[]>& var) { return var.len ; }

    template <is::num_t T1> auto type(const ap::var<T1[]>& var) { return T1(); }
    template <is::num_t T1> auto name(const ap::var<T1[]>& var) { return var.name; }
    template <is::num_t T1> auto len (const ap::var<T1[]>& var) { return var.len ; }
}

#endif
