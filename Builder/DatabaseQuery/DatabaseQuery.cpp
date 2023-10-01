#if 0 

    In this example, the QueryBuilder class allows you to build a SQL query step by step. 
    You can add optional clauses such as SELECT, WHERE, ORDER BY, and LIMIT. 
    Method chaining is utilized to make the code concise and expressive.

    select: Sets the SELECT clause of the SQL query.
    from: Sets the FROM clause of the SQL query.
    where: Sets the WHERE clause of the SQL query.
    orderBy: Sets the ORDER BY clause of the SQL query.
    limit: Sets the LIMIT clause of the SQL query.
    The build() method constructs and returns the final SQL query as a string.

#endif

#include <iostream>
#include <string>
#include <memory>

using namespace std;

class QueryBuilder{
    std::string query{};
    public:
        QueryBuilder(){
            cout << __func__ << endl;
            query = "SELECT + FROM " ;
        }
        QueryBuilder& select(const std::string & columns){
            query += columns + " ";
            return *this;
        }
        QueryBuilder& from(const std::string & table){
            query += "FROM " + table + " " ;
            return *this;
        }
        QueryBuilder& where(const std::string & condition){
            query += "WHERE " + condition + " " ;
            return *this;
        }
        QueryBuilder& orderBy(const std::string & column){
            query += "ORDER BY "+ column + " " ;
            return *this;
        }
        QueryBuilder& limit(int count){
            query += "LIMIT " + std::to_string(count) + " ";
            return *this;
        }
        std::string build(){
            return query;
        }
};

int main(){
    std::string myQuery = QueryBuilder()
                                .select("name , age")
                                .from("users")
                                .where("age > 18")
                                .orderBy("name")
                                .limit(100)
                                .build();

    cout << "MyQuery : " << myQuery << endl;
}